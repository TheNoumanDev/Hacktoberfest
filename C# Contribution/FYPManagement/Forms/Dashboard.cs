using iTextSharp.text;
using iTextSharp.text.pdf;
using System;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Windows.Forms;
using Font = iTextSharp.text.Font;

namespace FYPManagement.Forms
{
    public partial class Dashboard : Form
    {
        public Dashboard()
        {
            InitializeComponent();
            SaveBtn.Hide();        
            CancelBtn.Hide();
            SaveUpdatedProjecBtn.Hide();
            AbortProjectChangesBtn.Hide();
            SaveAdvisorChangesBtn.Hide();
            AbortAdvisorChangesBtn.Hide();
            StudentsBtn.PerformClick();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            if(this.WindowState == FormWindowState.Normal)
            {
                this.WindowState = FormWindowState.Maximized;
            }
            else
            {
                this.WindowState = FormWindowState.Normal;
            }
        }

        

        private void roundPictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            
        }

        private void roundPictureBox3_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.WindowState == FormWindowState.Normal)
            {
                this.WindowState = FormWindowState.Maximized;

            }
            else
            {
                this.WindowState = FormWindowState.Normal;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void roundPictureBox6_MouseEnter(object sender, EventArgs e)
        {

        }

        private void GradesBtn_MouseEnter(object sender, EventArgs e)
        {
            GradesBtn.BackColor = Color.FromArgb(152, 204, 253);
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void ViewStudentBtn_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA Select S.id,S.RegistrationNo, [FirstName] ,[LastName], [Contact], [Email], [DateOfBirth], (SELECT VALUE FROM [Lookup] where Gender = Id) as Gender from Student S JOIN Person P ON P.id = S.id", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            StudentsDatagrid.DataSource = dt;

        }

        private void AddStudentBtn_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA INSERT Person VALUES(@FirstName, @LastName, @Contact, @Email, @DateOfBirth, @Gender)", con);
            cmd.Parameters.AddWithValue("@FirstName", FirstNameTxt.Text);
            cmd.Parameters.AddWithValue("@LastName", LastNameTxt.Text);
            cmd.Parameters.AddWithValue("@Contact", ContactTxt.Text);
            cmd.Parameters.AddWithValue("@Email", EmailTxt.Text);
            cmd.Parameters.Add("@DateOfBirth", SqlDbType.Date).Value = DateOfBirthPicker.Value.Date;
            if(genderCombobox.SelectedItem.ToString() == "Female")
            {
                cmd.Parameters.AddWithValue("@Gender", 2);
            }
            else
            {
                cmd.Parameters.AddWithValue("@Gender", 1);
            }
            
            cmd.ExecuteNonQuery();
            string Name = FirstNameTxt.Text + " " + LastNameTxt.Text;
            SqlCommand getId = new SqlCommand("USE ProjectA Select id FROM Person Where FirstName +' '+LastName = '"+Name+"';", con);
            SqlDataReader dr = getId.ExecuteReader();
            int id = 0;
            while (dr.Read())
            {
                id = int.Parse(dr[0].ToString());
            }
            dr.Close();
            SqlCommand SaveStnd = new SqlCommand("USE ProjectA INSERT Student VALUES (@id, @RegistrationNo)", con);
            SaveStnd.Parameters.AddWithValue("@id", id);
            SaveStnd.Parameters.AddWithValue("@RegistrationNo", "2020-CS-"+id);
            SaveStnd.ExecuteNonQuery();
            MessageBox.Show("Successfully saved");
            StudentsBtn.PerformClick();
        }

        private void UpdateStudentBtn_Click(object sender, EventArgs e)
        {
            
            
            this.FirstNameTxt.Text = StudentsDatagrid.CurrentRow.Cells["FirstName"].Value.ToString();
            this.LastNameTxt.Text = StudentsDatagrid.CurrentRow.Cells["LastName"].Value.ToString();
            this.ContactTxt.Text = StudentsDatagrid.CurrentRow.Cells["Contact"].Value.ToString();
            this.EmailTxt.Text = StudentsDatagrid.CurrentRow.Cells["Email"].Value.ToString();
            this.DateOfBirthPicker.Text = StudentsDatagrid.CurrentRow.Cells["DateOfBirth"].Value.ToString();
            this.genderCombobox.Text = StudentsDatagrid.CurrentRow.Cells["Gender"].Value.ToString();
            AddStudentButton.PerformClick();
            SaveBtn.Show();
            CancelBtn.Show();

            


        }


        private void pictureBox1_Click_1(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void SaveBtn_Click(object sender, EventArgs e)
        {
            string Sname = StudentsDatagrid.CurrentRow.Cells["id"].Value.ToString();
            string col = StudentsDatagrid.SelectedCells[0].OwningColumn.HeaderText;
            var con = Configuration.getInstance().getConnection();
            int Gender = 1;
            if(genderCombobox.SelectedItem.ToString() == "Female" )
            {
                Gender = 2;  
            }
            
            SqlCommand cmd = new SqlCommand("USE ProjectA UPDATE Person SET FirstName = '" + FirstNameTxt.Text + "', LastName = '" + LastNameTxt.Text + "', Email ='" + EmailTxt.Text + "', Contact = '" + ContactTxt.Text + "', Gender = " + Gender + ", DateOfBirth = '" + DateOfBirthPicker.Value.Date + "' WHERE id = " + Sname + ";", con);
            
            
            //cmd.ExecuteNonQuery(); 
            
            ViewStudentBtn.PerformClick();
            cmd.ExecuteNonQuery();
            CancelBtn.PerformClick();

        }

        private void CancelBtn_Click(object sender, EventArgs e)
        {
            FirstNameTxt.Clear();
            LastNameTxt.Clear();
            ContactTxt.Clear();
            EmailTxt.Clear();

            SaveBtn.Hide();
            CancelBtn.Hide();
            StudentsBtn.PerformClick();
        }

        private void Dashboard_Load(object sender, EventArgs e)
        {
            StudentsBtn.PerformClick();
            ViewStudentBtn.PerformClick();
            ViewProject.PerformClick();
        }

        private void DeleteStudentBtn_Click(object sender, EventArgs e)
        {
            string Sname = StudentsDatagrid.CurrentRow.Cells["id"].Value.ToString();
            var con = Configuration.getInstance().getConnection();
            SqlCommand delGroup = new SqlCommand("USE ProjectA DELETE FROM GroupStudent WHERE Studentid = '" + Sname + "';", con);
            delGroup.ExecuteNonQuery();
            SqlCommand delStudent = new SqlCommand("USE ProjectA DELETE FROM Student WHERE id = '" + Sname + "';", con);
            delStudent.ExecuteNonQuery();
            SqlCommand cmd = new SqlCommand("USE ProjectA DELETE FROM Person WHERE id = '" + Sname + "';", con);
            cmd.ExecuteNonQuery();
            MessageBox.Show("Successfully Deleted");
            ViewStudentBtn.PerformClick();

        }

        private void SearchTxt_TextChanged(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            if (SearchOn.Text == "")
            {
                SearchOn.Text = "FirstName";
            }

            SqlCommand cmd = new SqlCommand("USE ProjectA Select * FROM Person P JOIN Student S ON P.id = S.id  WHERE "+ SearchOn.Text.ToString() + " LIKE '%" + SearchTxt.Text.ToString() + "%';", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            StudentsDatagrid.DataSource = dt;
            

        }

        private void StudentsBtn_Click(object sender, EventArgs e)
        {
            label7.Hide();
            label6.Hide();
            AddStudentBtn.Hide();
            label2.Hide();
            label3.Hide();
            label4.Hide();
            label5.Hide();
            FirstNameTxt.Hide();
            LastNameTxt.Hide();
            ContactTxt.Hide();
            EmailTxt.Hide();
            genderCombobox.Hide();
            DateOfBirthPicker.Hide();
            
            tabControl1.SelectedIndex = 0;
            ViewStudentBtn.PerformClick();

        }

        private void Groups_Click(object sender, EventArgs e)
        {
            label37.Hide();
            Status.Hide();
            label36.Hide();
            SaveAssignStudent.Hide();
            AbortStudentBtn.Hide();
            AssignStudentBtn.Show();
            ProjectsLbls.Text = "Assigned Projects";
            AssignSaveBtn.Hide();
            AbortAssignBtn.Hide();
            GroupsLbl.Hide();
            this.GroupDataGrid.Size = new System.Drawing.Size(794, 336);
            PendingGroupsDataGrid.Hide();
            AssignProjectBtn.Show();
            tabControl1.SelectedIndex = 1;
            ViewGroupBtn.PerformClick();

        }

        private void ProjectsBtn_Click(object sender, EventArgs e)
        {

            tabControl1.SelectedIndex = 2;
            ViewProject.PerformClick();
            
        }

        private void EvaluationBtn_Click(object sender, EventArgs e)
        {
            EvaName.Hide();
            Weightage.Hide();
            TotalMarks.Hide();
            saveEvaluation.Hide();
            AbortEvaluationBtn.Hide();
            SaveUpdatedEvaluation.Hide();
            AbortUpdatedEvaluation.Hide();
            label30.Hide();
            label31.Hide();
            label32.Hide();
            label33.Hide();
            label34.Hide();
            tabControl1.SelectedIndex = 3;
            viewEvaluationBtn.PerformClick();
        }

        private void AdvisorsBtn_Click(object sender, EventArgs e)
        {
            tabControl1.SelectedIndex = 4;
            ViewAdvisorBtn.PerformClick();
        }

        private void AddProjectBtn_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand Saveproject = new SqlCommand("USE ProjectA INSERT Project VALUES (@Description, @title)", con);
            Saveproject.Parameters.AddWithValue("@Description", DiscriptionTxt.Text);
            Saveproject.Parameters.AddWithValue("@title", titletxt.Text);
            Saveproject.ExecuteNonQuery();
            MessageBox.Show("Successfully Saved");
            ViewProject.PerformClick();
        }

        private void ViewProject_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA Select Id,Title, Description from Project", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            ProjectDataGrid.DataSource = dt;
        }

        private void UpdateProjectBtn_Click(object sender, EventArgs e)
        {
            SaveUpdatedProjecBtn.Show();
            AbortProjectChangesBtn.Show();
            this.titletxt.Text = ProjectDataGrid.CurrentRow.Cells["Title"].Value.ToString();
            this.DiscriptionTxt.Text = ProjectDataGrid.CurrentRow.Cells["Description"].Value.ToString();
           
        }

        private void SaveUpdatedProjecBtn_Click(object sender, EventArgs e)
        {
            string ProjectId = ProjectDataGrid.CurrentRow.Cells["id"].Value.ToString();
            var con = Configuration.getInstance().getConnection();

            SqlCommand cmd = new SqlCommand("USE ProjectA UPDATE Project SET Title = '" + titletxt.Text + "', Description = '" + DiscriptionTxt.Text + "' WHERE id = " + int.Parse(ProjectId) + ";", con);


            //cmd.ExecuteNonQuery(); 
            MessageBox.Show("Updated Successfully!");
            
            cmd.ExecuteNonQuery();
            SaveUpdatedProjecBtn.Hide();
            AbortProjectChangesBtn.Hide();
            ViewProject.PerformClick();
        }

        private void AbortProjectChangesBtn_Click(object sender, EventArgs e)
        {
            titletxt.Clear();
            DiscriptionTxt.Clear();

            SaveUpdatedProjecBtn.Hide();
            AbortProjectChangesBtn.Hide();
            ViewProject.PerformClick();
        }

        private void DeleteProjectBtn_Click(object sender, EventArgs e)
        {
            string ProjectId = ProjectDataGrid.CurrentRow.Cells["Id"].Value.ToString();
            var con = Configuration.getInstance().getConnection();
            SqlCommand delProjectAdvisor = new SqlCommand("USE ProjectA DELETE FROM ProjectAdvisor WHERE ProjectId = '" + ProjectId + "';", con);
            delProjectAdvisor.ExecuteNonQuery();
            SqlCommand cmd = new SqlCommand("USE ProjectA DELETE FROM GroupProject WHERE ProjectId = '" + ProjectId + "';", con);
            cmd.ExecuteNonQuery();
            SqlCommand delProj = new SqlCommand(" DELETE FROM [Project] WHERE Id = '" + ProjectId + "';", con);
            delProj.ExecuteNonQuery();
            MessageBox.Show("Successfully Deleted");
            ProjectsBtn.PerformClick();
        }

        private void AssignAdvisorBtn_Click(object sender, EventArgs e)
        {
            tabControl1.SelectedIndex = 5;
            var con = Configuration.getInstance().getConnection();
            SqlCommand getId = new SqlCommand("USE ProjectA Select id FROM Project", con);
            SqlDataReader dr = getId.ExecuteReader();
            while (dr.Read())
            {
                AssignAdvisorProjectId.Items.Add(int.Parse(dr[0].ToString()));
            }
            dr.Close();
            AssignAdviosrAdvisorID.Enabled = false;
            AdvisorRoleGB.Enabled = false;
            ViewAssignedBtn.PerformClick();
           
        }

        private void AssignAdvisor_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA INSERT ProjectAdvisor VALUES (@AdvisorId, @ProjectId, @AdvisorRole, @AssignmentDate)", con);
            cmd.Parameters.AddWithValue("@AdvisorId", int.Parse(AssignAdviosrAdvisorID.Text.ToString()));
            cmd.Parameters.AddWithValue("@ProjectId", int.Parse(AssignAdvisorProjectId.Text.ToString()));
            if (AdvisorRoleGB.Text == "Industry Advisor")
            {
                cmd.Parameters.AddWithValue("@AdvisorRole", 14);
            }
            else
            {
                cmd.Parameters.AddWithValue("@AdvisorRole", (AdvisorRoleGB.SelectedIndex + 11));
            }
            cmd.Parameters.AddWithValue("@AssignmentDate", SqlDbType.Date).Value = AssignmentDatePicker.Value.Date;
            cmd.ExecuteNonQuery();
            AdvisorRoleGB.Items.Clear();
            AdvisorRoleGB.Text = "";
            AssignAdviosrAdvisorID.Text = "";
            AssignAdvisorProjectId.Text = "";
            AssignAdvisorBtn.PerformClick();



        }

        private void AddAdvisorBtn_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand maxID = new SqlCommand("SELECT Max(id) FROM Advisor", con);
            SqlDataReader dr = maxID.ExecuteReader();
            int id = 99;
            while (dr.Read())
            {
                id = int.Parse(dr[0].ToString());
            }
            dr.Close();

            SqlCommand SaveAdvisor = new SqlCommand("USE ProjectA INSERT Advisor VALUES (@id, @Designation, @Salary)", con);
            SaveAdvisor.Parameters.AddWithValue("@id", id+1);
            SaveAdvisor.Parameters.AddWithValue("@Designation", DesignationCB.SelectedIndex+6);
            SaveAdvisor.Parameters.AddWithValue("@Salary", int.Parse(SalaryUpDown.Text));
            
            SaveAdvisor.ExecuteNonQuery();
            MessageBox.Show("Successfully saved");
            ViewAdvisorBtn.PerformClick();
        }

        private void ViewAdvisorBtn_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA Select A.Id, L.Value AS Designation, A.Salary from Advisor A JOIN [Lookup] L ON A.Designation = L.Id", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            AdvisorDataGrid.DataSource = dt;
        }

        private void UpdateAdvisorBtn_Click(object sender, EventArgs e)
        {
            SaveAdvisorChangesBtn.Show();
            AbortAdvisorChangesBtn.Show();
            this.SalaryUpDown.Value = int.Parse(AdvisorDataGrid.CurrentRow.Cells["Salary"].Value.ToString());
            this.DesignationCB.Text = AdvisorDataGrid.CurrentRow.Cells["Designation"].Value.ToString();
            
        }

        private void SaveAdvisorChangesBtn_Click(object sender, EventArgs e)
        {
            string AdvisorId = AdvisorDataGrid.CurrentRow.Cells["id"].Value.ToString();
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA UPDATE Advisor SET id = '" + int.Parse(AdvisorId) + "', Designation = '" + (DesignationCB.SelectedIndex + 6) + "' WHERE id = " + int.Parse(AdvisorId) + ";", con);
            cmd.ExecuteNonQuery();
            ViewAdvisorBtn.PerformClick();
            SaveAdvisorChangesBtn.Hide();
            AbortAdvisorChangesBtn.Hide();
        }

        private void AbortAdvisorChangesBtn_Click(object sender, EventArgs e)
        {
            SalaryUpDown.Text = "";
            DesignationCB.SelectedIndex = 0;
        }

        private void DesignationCB_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void DeleteAdvisor_MouseHover(object sender, EventArgs e)
        {
             
        }

        private void DeleteAdvisor_MouseEnter(object sender, EventArgs e)
        {
            DeleteAdvisor.BackColor = Color.Red;
        }

        private void DeleteAdvisor_MouseLeave(object sender, EventArgs e)
        {
            DeleteAdvisor.BackColor = Color.White;
        }

        private void AddAdvisorBtn_MouseEnter(object sender, EventArgs e)
        {
            AddAdvisorBtn.BackColor = Color.Green;
        }

        private void AddAdvisorBtn_MouseLeave(object sender, EventArgs e)
        {
            AddAdvisorBtn.BackColor = Color.White;
        }

        private void AddGroupBtn_Click(object sender, EventArgs e)
        {
            DateTime dateTime = DateTime.Today;
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA  INSERT [Group] Values (@Created_On) ", con);
            cmd.Parameters.AddWithValue("@Created_On", dateTime);
            cmd.ExecuteNonQuery();
            ViewGroupBtn.PerformClick();
        }

        private void ViewGroupBtn_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA Select G.Id AS GroupID, P.Id AS ProjectId, P.Title AS Title from [Group] G JOIN GroupProject GP ON G.Id = Gp.GroupId JOIN Project P ON Gp.ProjectId = P.Id", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            GroupDataGrid.DataSource = dt;
        }

        private void AssignmentDatePicker_ValueChanged(object sender, EventArgs e)
        {

        }

        private void AdvisorRoleGB_SelectedIndexChanged(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            
            //int Role = 0;
            //if (AdvisorRoleGB.Text == "Industry Advisor")
            //{
            //    Role = 14;
            //}
            //else
            //{
            //    Role = AdvisorRoleGB.SelectedIndex + 11;    
            //}
            SqlCommand cmd = new SqlCommand("SELECT id FROM Advisor Where id NOT IN (SELECT AdvisorId from ProjectAdvisor where ProjectId = "+int.Parse(AssignAdvisorProjectId.Text.ToString())+")", con);
            SqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                AssignAdviosrAdvisorID.Items.Add(dr[0].ToString());
            }
            dr.Close();
            AssignAdviosrAdvisorID.Enabled = true;
        }

        private void AssignAdvisorProjectId_SelectedIndexChanged(object sender, EventArgs e)
        {

            var con = Configuration.getInstance().getConnection();
            SqlCommand getId = new SqlCommand("SELECT DISTINCT Value FROM [Lookup] Where id > 10 AND id NOT IN (SELECT AdvisorRole FROM ProjectAdvisor where ProjectId = "+int.Parse(AssignAdvisorProjectId.Text.ToString())+") ", con);
            SqlDataReader dr = getId.ExecuteReader();
            while (dr.Read())
            {
                AdvisorRoleGB.Items.Add(dr[0].ToString());
            }
            dr.Close();
            
            AdvisorRoleGB.Enabled = true;
            getId = new SqlCommand("USE ProjectA SELECT A.id, (SELECT VALUE FROM [Lookup] where A.Designation = Id) as Designation FROM Advisor A  Where id NOT IN (SELECT AdvisorId from ProjectAdvisor where ProjectId = " + int.Parse(AssignAdvisorProjectId.Text.ToString()) + ") ", con);
            SqlDataAdapter da = new SqlDataAdapter(getId);
            DataTable dt = new DataTable();
            da.Fill(dt);
            ProjectAdvisorDataGrid.DataSource = dt;
        }

        private void AssignAdviosrAdvisorID_SelectedIndexChanged(object sender, EventArgs e)
        {
            AssignAdviosrAdvisorID.Enabled = true;
        }

        private void ViewAssignedBtn_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA SELECT ProjectID, A.AdvisorId, (SELECT VALUE FROM [Lookup] where A.AdvisorRole = Id) as AdvisorRole FROM ProjectAdvisor A ORDER BY ProjectID", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            ProjectAssignmentDataGrid.DataSource = dt;
            //cmd = new SqlCommand("");
        }

        private void AssignProjectBtn_Click(object sender, EventArgs e)
        {
            
            AssignSaveBtn.Show();
            AbortAssignBtn.Show(); 
            AssignProjectBtn.Hide();
            ProjectsLbls.Text = "All Projects";
            GroupsLbl.Text = "Pending Groups";
            GroupsLbl.Show();
            PendingGroupsDataGrid.Show();
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA Select Id,Title, Description from Project", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);            
            GroupDataGrid.DataSource = dt;
            this.GroupDataGrid.Size = new System.Drawing.Size(527, 304);

            cmd = new SqlCommand("USE ProjectA SELECT G.id as GroupID, Created_On FROM [Group] G LEFT JOIN GroupProject GP ON G.id = GP.GroupId Where ProjectId is NUll ", con);
            SqlDataAdapter daa = new SqlDataAdapter(cmd);
            DataTable dta = new DataTable();
            daa.Fill(dta);
            PendingGroupsDataGrid.DataSource = dta;
        }

        private void AbortAssignBtn_Click(object sender, EventArgs e)
        {
            Groups.PerformClick();
            this.GroupDataGrid.Size = new System.Drawing.Size(794, 336);
        }

        private void AssignSaveBtn_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            DateTime dateTime = DateTime.Today;
            int ProjectId = int.Parse(GroupDataGrid.CurrentRow.Cells["Id"].Value.ToString());
            int GroupId = int.Parse(PendingGroupsDataGrid.CurrentRow.Cells["GroupID"].Value.ToString());
            SqlCommand SaveAdvisor = new SqlCommand("USE ProjectA INSERT GroupProject VALUES (@ProjectId, @GroupId, @AssignmentDate)", con);
            SaveAdvisor.Parameters.AddWithValue("@ProjectId", ProjectId);
            SaveAdvisor.Parameters.AddWithValue("@GroupId", GroupId);
            SaveAdvisor.Parameters.AddWithValue("@AssignmentDate", dateTime);
            SaveAdvisor.ExecuteNonQuery();
            MessageBox.Show("Successfully saved");
            Groups.PerformClick();
            this.GroupDataGrid.Size = new System.Drawing.Size(794, 336);


        }

        private void AddEvaluationBtn_Click(object sender, EventArgs e)
        {
            label33.Show();
            label34.Show();
            EvaName.Show();
            Weightage.Show();
            TotalMarks.Show();
            saveEvaluation.Show();
            AbortEvaluationBtn.Show();
            label30.Show();
            label31.Show();
            label32.Show();


        }

        private void saveEvaluation_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand SaveAdvisor = new SqlCommand("USE ProjectA INSERT INTO Evaluation VALUES (@Name, @TotalMarks, @TotalWeightage)", con);
            SaveAdvisor.Parameters.AddWithValue("@Name", EvaName.Text);
            SaveAdvisor.Parameters.AddWithValue("@TotalMarks", TotalMarks.Value);
            SaveAdvisor.Parameters.AddWithValue("@TotalWeightage", Weightage.Value);
            SaveAdvisor.ExecuteNonQuery();
            MessageBox.Show("Successfully saved");
            EvaluationBtn.PerformClick();
        }

        private void AbortEvaluationBtn_Click(object sender, EventArgs e)
        {
            EvaluationBtn.PerformClick();
        }

        private void viewEvaluationBtn_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA SELECT * from Evaluation", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            EvaluationsDataGrid.DataSource = dt;
        }

        private void NotEvaluated_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA SELECT G.Id as GroupId, G.Created_On FROM GroupEvaluation GE RIGHT JOIN [Group] G ON GE.GroupId = G.Id where GE.EvaluationId is NULL", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            EvaluationsDataGrid.DataSource = dt;
        }

        private void groupEvaluations_Click(object sender, EventArgs e)
        {
            headE.Hide();
            headGE.Location = new System.Drawing.Point(395, 196);
            
            ObtainedMarks.Hide();
            GroupIDEva.Hide();
            label27.Hide();
           
            label29.Hide();
            label35.Hide();
            MarkEva.Hide();
            AbortEvaluationsBtn.Hide();

            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA SELECT GE.GroupId,GE.EvaluationId,GE.ObtainedMarks, E.TotalMarks, E.TotalWeightage, GE.EvaluationDate FROM GroupEvaluation GE JOIN Evaluation E ON GE.EvaluationId = E.Id ORDER BY GroupId", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            GroupEvaluationDataGrid.DataSource = dt;
            this.GroupEvaluationDataGrid.Size = new System.Drawing.Size(794, 336);
            GroupsNotEvaluatedDataGrid.Hide();
            tabControl1.SelectedIndex = 6;

        }

        private void MarkEvaluationBtn_Click(object sender, EventArgs e)
        {
            headGE.Text = "Groups";
            headGE.Left = 195;
            headE.Show();
            this.GroupEvaluationDataGrid.Size = new System.Drawing.Size(527, 304);
            GroupsNotEvaluatedDataGrid.Show();
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("SELECT DISTINCT GP.GroupId, GP.ProjectId, P.Title, CAST(GP.AssignmentDate as date) as [Assignment Date] FROM GroupProject GP JOIN Project P ON P.Id = GP.ProjectId LEFT JOIN GroupStudent GS ON GS.GroupId = GP.GroupId WHERE GS.GroupId is NOT NULL", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            GroupEvaluationDataGrid.DataSource = dt;
            GroupIDEva.Text = GroupEvaluationDataGrid.CurrentRow.Cells["GroupId"].Value.ToString();
           
            MarkEva.Show();
            AbortEvaluationsBtn.Show();
            GroupIDEva.Show();
       
            ObtainedMarks.Show();
            label27.Show();
          
            label29.Show();
            label35.Show();
        }

        private void ViewGroupWise_Click(object sender, EventArgs e)
        {
            groupEvaluationsBtn.PerformClick();
            
        }

        private void AbortEva_Click(object sender, EventArgs e)
        {
            groupEvaluationsBtn.PerformClick();
        }

        private void GroupIDEva_TextChanged(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            int groupId = int.Parse(GroupEvaluationDataGrid.CurrentRow.Cells["GroupId"].Value.ToString());
            SqlCommand cmd = new SqlCommand("SELECT * FROM Evaluation E where E.id  Not IN (SELECT EvaluationId from GroupEvaluation ge where GroupId = "+groupId+") ", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            GroupsNotEvaluatedDataGrid.DataSource = dt;
            int value = GroupsNotEvaluatedDataGrid.Rows.Count;
            
          
            
        }

        private void GroupsNotEvaluatedDataGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        { 
            int id = int.Parse(GroupsNotEvaluatedDataGrid.CurrentRow.Cells["Id"].Value.ToString());
            var con = Configuration.getInstance().getConnection();
            
            SqlCommand cmd = new SqlCommand("SELECT TotalMarks FROM Evaluation where id ="+id+";", con);
            SqlDataReader dr = cmd.ExecuteReader();
            int getMax = 0;
            while (dr.Read())
            {
                getMax = int.Parse(dr[0].ToString());
            }
            dr.Close();
            ObtainedMarks.Maximum = getMax;


        }

        private void MarkEva_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            DateTime dateTime = DateTime.Today;
            SqlCommand SaveGroupEvaluation = new SqlCommand("USE ProjectA INSERT GroupEvaluation VALUES (@GroupId, @EvaluationId, @ObtainedMarks, @EvaluationDate)", con);
            SaveGroupEvaluation.Parameters.AddWithValue("@GroupId", int.Parse(GroupIDEva.Text.ToString()));
            SaveGroupEvaluation.Parameters.AddWithValue("@EvaluationId", int.Parse(GroupsNotEvaluatedDataGrid.CurrentRow.Cells["Id"].Value.ToString().ToString()));
            SaveGroupEvaluation.Parameters.AddWithValue("@ObtainedMarks", ObtainedMarks.Value);
            SaveGroupEvaluation.Parameters.AddWithValue("@EvaluationDate", dateTime);
            SaveGroupEvaluation.ExecuteNonQuery();
            MessageBox.Show("Successfully saved");
            viewGroupEvaluationsBtn.PerformClick();

        }

        private void AssignStudentBtn_Click(object sender, EventArgs e)
        {
            label37.Show();
            Status.Show();
            label36.Show();
            SaveAssignStudent.Show();
            AbortStudentBtn.Show();
            AssignStudentBtn.Hide();
            ProjectsLbls.Text = "Students";
            GroupsLbl.Text = "Groups";
            GroupsLbl.Show();
            PendingGroupsDataGrid.Show();
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("USE ProjectA Select S.id,S.RegistrationNo, [FirstName] ,[LastName], [Contact], [Email], [DateOfBirth], (SELECT VALUE FROM [Lookup] where Gender = Id) as Gender from Student S JOIN Person P ON P.id = S.id where S.Id NOT IN (Select G.StudentId FROM GroupStudent G)", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            GroupDataGrid.DataSource = dt;
            this.GroupDataGrid.Size = new System.Drawing.Size(527, 304);

            cmd = new SqlCommand("USE ProjectA SELECT G.id as GroupID, Created_On FROM [Group] G JOIN GroupProject GP ON G.id = GP.GroupId ", con);
            SqlDataAdapter daa = new SqlDataAdapter(cmd);
            DataTable dta = new DataTable();
            daa.Fill(dta);
            PendingGroupsDataGrid.DataSource = dta;
        }

        private void AbortStudentBtn_Click(object sender, EventArgs e)
        {
            Groups.PerformClick();
            this.GroupDataGrid.Size = new System.Drawing.Size(794, 336);
        }

        private void SaveAssignStudent_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            DateTime dateTime = DateTime.Today;
            int StudentId = int.Parse(GroupDataGrid.CurrentRow.Cells["id"].Value.ToString());
            int GroupId = int.Parse(PendingGroupsDataGrid.CurrentRow.Cells["GroupID"].Value.ToString());
            SqlCommand SaveAdvisor = new SqlCommand("USE ProjectA INSERT GroupStudent VALUES (@GroupId, @StudentId, @Status, @AssignmentDate)", con);
            SaveAdvisor.Parameters.AddWithValue("@GroupId", GroupId);
            SaveAdvisor.Parameters.AddWithValue("@StudentId", StudentId);
            SaveAdvisor.Parameters.AddWithValue("@Status", Status.SelectedIndex+3);
            SaveAdvisor.Parameters.AddWithValue("@AssignmentDate", dateTime);
            SaveAdvisor.ExecuteNonQuery();
            MessageBox.Show("Successfully saved");
            Groups.PerformClick();
            this.GroupDataGrid.Size = new System.Drawing.Size(794, 336);
        }

        private void AddStudentButton_Click(object sender, EventArgs e)
        {
            label7.Show();
            label6.Show();
            AddStudentBtn.Show();
            label2.Show();
            label3.Show();
            label4.Show();
            label5.Show();
            FirstNameTxt.Show();
            LastNameTxt.Show();
            ContactTxt.Show();
            EmailTxt.Show();
            genderCombobox.Show();
            DateOfBirthPicker.Show();
        }

        private void DeletGroupBtn_Click(object sender, EventArgs e)
        {
            string GroupId = GroupDataGrid.CurrentRow.Cells["GroupId"].Value.ToString();
            var con = Configuration.getInstance().getConnection();
            SqlCommand delGe = new SqlCommand("USE ProjectA DELETE FROM GroupEvaluation WHERE GroupId = '" + GroupId + "';", con);
            delGe.ExecuteNonQuery();
            SqlCommand delStudent = new SqlCommand("USE ProjectA DELETE FROM GroupStudent WHERE GroupId = '" + GroupId + "';", con);
            delStudent.ExecuteNonQuery();
            SqlCommand cmd = new SqlCommand("USE ProjectA DELETE FROM GroupProject WHERE GroupId = '" + GroupId + "';", con);
            cmd.ExecuteNonQuery();
            SqlCommand delGroup = new SqlCommand("USE ProjectA DELETE FROM [Group] WHERE Id = '" + GroupId + "';", con);
            delGroup.ExecuteNonQuery();
            MessageBox.Show("Successfully Deleted");
            Groups.PerformClick();
        }

        private void UpdateEvaluations_Click(object sender, EventArgs e)
        {
            SaveUpdatedEvaluation.Show();
            AbortUpdatedEvaluation.Show();
            label33.Show();
            label34.Show();
            EvaName.Show();
            Weightage.Show();
            TotalMarks.Show();
            label30.Show();
            label31.Show();
            label32.Show();
            this.EvaName.Text = EvaluationsDataGrid.CurrentRow.Cells["Name"].Value.ToString();
            this.TotalMarks.Text = EvaluationsDataGrid.CurrentRow.Cells["TotalMarks"].Value.ToString();
            this.Weightage.Text = EvaluationsDataGrid.CurrentRow.Cells["TotalWeightage"].Value.ToString();
                        

        }

        private void AbortUpdatedEvaluation_Click(object sender, EventArgs e)
        {
            EvaluationBtn.PerformClick();
        }

        private void SaveUpdatedEvaluation_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand SaveEvaluation = new SqlCommand("USE ProjectA Update Evaluation SET Name = '"+ EvaName.Text + "', TotalMarks = "+ TotalMarks.Value + ", TotalWeightage = "+Weightage.Value+" where Id =  "+ int.Parse(EvaluationsDataGrid.CurrentRow.Cells["Id"].Value.ToString())+";", con);
            SaveEvaluation.ExecuteNonQuery();
            MessageBox.Show("Successfully saved");
            EvaluationBtn.PerformClick();
        }

        private void DeletEvaluation_Click(object sender, EventArgs e)
        {
            string EvaluationId = EvaluationsDataGrid.CurrentRow.Cells["Id"].Value.ToString();
            var con = Configuration.getInstance().getConnection();
            SqlCommand delGe = new SqlCommand("USE ProjectA DELETE FROM GroupEvaluation WHERE EvaluationId = '" + EvaluationId + "';", con);
            delGe.ExecuteNonQuery();
            SqlCommand cmd = new SqlCommand("USE ProjectA DELETE FROM [Evaluation] WHERE Id = '" + EvaluationId + "';", con);
            cmd.ExecuteNonQuery();
            MessageBox.Show("Successfully Deleted");
            EvaluationBtn.PerformClick();

        }

        private void GroupEvaluationDataGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            GroupIDEva.Text = GroupEvaluationDataGrid.CurrentRow.Cells["GroupId"].Value.ToString();
        }

        private void DeleteEvaluation_Click(object sender, EventArgs e)
        {
            string GroupId = GroupEvaluationDataGrid.CurrentRow.Cells["GroupId"].Value.ToString();
            string EvaluationId = GroupEvaluationDataGrid.CurrentRow.Cells["EvaluationId"].Value.ToString();
            var con = Configuration.getInstance().getConnection();
            SqlCommand delGe = new SqlCommand("USE ProjectA DELETE FROM GroupEvaluation WHERE EvaluationId = '" + EvaluationId + "' AND GroupID = '" + GroupId + "';", con);
            delGe.ExecuteNonQuery();
            MessageBox.Show("Successfully Deleted");
            viewGroupEvaluationsBtn.PerformClick();
        }

        private void ReportsBtn_Click(object sender, EventArgs e)
        {
            tabControl1.SelectedIndex = 7;
        }

        private void AllProjBtn_Click(object sender, EventArgs e)
        {
            generate_atten_report(1, "Project Report");
        }
        private DataTable getDATA()
        {
            var con = Configuration.getInstance().getConnection();
            int totalProj = 0;

            SqlCommand cmd = new SqlCommand("USE ProjectA SELECT COUNT(*) FROM Project", con);
            SqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                totalProj = int.Parse(dr[0].ToString());
            }
            dr.Close();
            DataTable dt = new DataTable();
            dt.Columns.Add("Projects", typeof(string));
            dt.Columns.Add("AdivsoryBoard", typeof(String));
            dt.Columns.Add("Students", typeof(String));

            cmd = new SqlCommand("USE ProjectA Select Id from Project", con);
            SqlDataReader dataReader = cmd.ExecuteReader();
            while (dataReader.Read())
            {
                int Pid = int.Parse(dataReader[0].ToString());
                SqlCommand sql = new SqlCommand("SELECT 'AdvisorId = '+CAST(AdvisorId as varchar) +' Role: '+ (SELECT Value FROM [Lookup] where PA.AdvisorRole = id)  From ProjectAdvisor PA Where ProjectId = " + Pid + "; ", con);
                SqlDataReader AdvisorData = sql.ExecuteReader();
                int j = 1;
                String Advisors = "";
                while (AdvisorData.Read())
                {
                    Advisors = Advisors + j + ": " + AdvisorData[0].ToString() + "\n";
                    j++;
                }


                SqlCommand Studnt = new SqlCommand("USE ProjectA SELECT S.RegistrationNo FROM GroupProject GP JOIN GroupStudent GS ON GP.GroupId = GS.GroupId JOIN Student S ON GS.StudentId = S.Id Where GP.ProjectId = " + Pid + ";", con);
                SqlDataReader StudntReader = Studnt.ExecuteReader();
                int k = 1;
                String StudentStr = "";
                while (StudntReader.Read())
                {
                    StudentStr = StudentStr + k + ": " + StudntReader[0].ToString() + "\n";
                    k++;
                }
                if (StudentStr == "")
                {
                    StudentStr = "N/A";
                }
                if (Advisors == "")
                {
                    Advisors = "N/A";
                }
                dt.Rows.Add(Pid, Advisors, StudentStr);
            }
            return dt;
        }
        private void generate_atten_report(int a, string name)
        {
            DataTable tb = new DataTable();
            if (a == 1)
            {
                tb = getDATA();
            }
            else if (a == 2)
            {
                tb = getStudetsMarks();
            }
            else if (a==3)
            {
                tb = NoGroupStudents();
            }
            else
            {
                tb = BelowAvg();
            }
            
            OpenFileDialog op = new OpenFileDialog();
            string folderPath = "";
            op.ValidateNames = false;
            op.CheckFileExists = false;
            op.CheckPathExists = true;
            op.FileName = "Folder Selection.";
            if (op.ShowDialog() == DialogResult.OK)
            {
                folderPath = Path.GetDirectoryName(op.FileName);
                FileStream fs = new FileStream(@"" + folderPath + @"\"+name+".pdf", FileMode.Create, FileAccess.Write, FileShare.None);
                Document doc = new Document();
                doc.SetPageSize(iTextSharp.text.PageSize.A4);
                iTextSharp.text.pdf.PdfWriter writer = PdfWriter.GetInstance(doc, fs);
                doc.Open();

                // Report Header
                BaseFont bfothead = BaseFont.CreateFont(BaseFont.TIMES_ROMAN, BaseFont.CP1250, BaseFont.NOT_EMBEDDED);
                Font fnt1 = new Font(bfothead, 16, 1, BaseColor.BLACK);
                Font fnt3 = new Font(bfothead, 14, 1, BaseColor.BLACK);
                Paragraph prg = new Paragraph();
                prg.Alignment = Element.ALIGN_CENTER;
                prg.Add(new Chunk("University Of Engineering And Technolgy, Lahore", fnt1));
                doc.Add(prg);
                prg = new Paragraph();
                prg.Alignment = Element.ALIGN_CENTER;
                Font fnt2 = new Font(bfothead, 12, 2, BaseColor.BLACK);
                prg.Add(new Chunk(name, fnt2));
                doc.Add(prg);
                Paragraph p = new Paragraph(new Chunk(new iTextSharp.text.pdf.draw.LineSeparator(0.0F, 100.0F, BaseColor.BLACK, Element.ALIGN_LEFT, 1)));
                doc.Add(p);
/*                prg = new Paragraph();
                prg.Alignment = Element.ALIGN_LEFT;
                prg.Add(new Chunk("\nCourse:   ", fnt3));
                prg.Add(new Chunk("CS-262 Database Systems", fnt2));
                prg.Add(new Chunk("\nSemester:   ", fnt3));
                prg.Add(new Chunk("Fall 2022", fnt2));
                prg.Add(new Chunk("\nLecturer:   ", fnt3));
                prg.Add(new Chunk("Samyan Qayyum Wahla\n", fnt2));

                doc.Add(prg);
                p = new Paragraph(new Chunk(new iTextSharp.text.pdf.draw.LineSeparator(0.0F, 100.0F, BaseColor.BLACK, Element.ALIGN_LEFT, 1)));
                doc.Add(p);*/


                prg = new Paragraph();
                prg.Alignment = Element.ALIGN_LEFT;
                prg.Add(new Chunk("\n"+name+"\n\n", fnt3));
                doc.Add(prg);

                // write second table
                PdfPTable table2 = new PdfPTable(tb.Columns.Count);
                //table header
                table2.WidthPercentage = 100;
                table2.TotalWidth = 500f;

                fnt1 = new Font(bfothead, 10, 1, BaseColor.WHITE);
                for (int i = 0; i < tb.Columns.Count; i++)
                {
                    PdfPCell cel = new PdfPCell();
                    cel.BackgroundColor = BaseColor.DARK_GRAY;
                    cel.HorizontalAlignment = Element.ALIGN_CENTER;
                    cel.AddElement(new Chunk(tb.Columns[i].ColumnName.ToUpper(), fnt1));
                    table2.AddCell(cel);
                }
                //table data
                for (int i = 0; i < tb.Rows.Count; i++)
                {
                    for (int j = 0; j < tb.Columns.Count; j++)
                    {
                        table2.AddCell(tb.Rows[i][j].ToString());
                    }
                }
                doc.Add(table2);



                doc.Close();
                writer.Close();
                fs.Close();
                MessageBox.Show("Report Generated!");
            }
        }
        private DataTable getStudetsMarks()
        {
            var con = Configuration.getInstance().getConnection();
            

            
            DataTable dt = new DataTable();
            dt.Columns.Add("GroupId", typeof(String));
            dt.Columns.Add("ProjectID", typeof(String));
            dt.Columns.Add("ProjectTitle", typeof(String));
            dt.Columns.Add("RegNo", typeof(String));
            dt.Columns.Add("Obtained",typeof(String));
            dt.Columns.Add("TotalMarks", typeof(String));
            dt.Columns.Add("Evaluation", typeof(String));

            SqlCommand cmd = new SqlCommand("USE ProjectA Select Id from [Group]", con);
            SqlDataReader dataReader = cmd.ExecuteReader();
            while (dataReader.Read())
            {
                int Pid = int.Parse(dataReader[0].ToString());
                SqlCommand sql = new SqlCommand("USE ProjectA SELECT  P.Id AS ProjectID, P.Title AS ProjectTitle, S.RegistrationNo, GE.ObtainedMarks, E.TotalMarks, E.Name AS Evalution From [Group] G JOIN GroupStudent GS on GS.GroupId = G.Id Join Student S ON GS.StudentId = S.id JOIN GroupEvaluation GE ON G.Id= ge.GroupId JOIN Evaluation E on E.id = GE.EvaluationId JOIN GroupProject GP ON G.Id = GP.GroupId JOIN Project P ON P.Id = GP.ProjectId Where g.id = " + Pid + "; ", con);
                SqlDataReader AdvisorData = sql.ExecuteReader();
                
                String Advisors = "";
                while (AdvisorData.Read())
                {

                    dt.Rows.Add(Pid, AdvisorData[0].ToString(), AdvisorData[1].ToString(), AdvisorData[2].ToString(), AdvisorData[3].ToString(), AdvisorData[4].ToString(), AdvisorData[5].ToString());
                    
                }

                if (Advisors == "")
                {
                    Advisors = "N/A";
                }
                
            }
            return dt;
        }

        private void GenerateMarksBtn_Click(object sender, EventArgs e)
        {
            generate_atten_report(2, "Marks Report");
        }
        private DataTable NoGroupStudents()
        {
            var con = Configuration.getInstance().getConnection();



            DataTable dt = new DataTable();
            dt.Columns.Add("RegistrationNo", typeof(String));
            dt.Columns.Add("Name", typeof(String));
            dt.Columns.Add("Email", typeof(String));
            dt.Columns.Add("Contact", typeof(String));
            SqlCommand sql = new SqlCommand("USE ProjectA SELECT S.RegistrationNo, P.FirstName+' '+p.LastName AS Name, P.Email, p.Contact FROM Student S LEFT JOIN [GroupStudent] GS ON GS.StudentId = S.Id JOIN Person P ON S.Id = P.Id  Where GS.StudentId is Null; ", con);
            SqlDataReader AdvisorData = sql.ExecuteReader();

                while (AdvisorData.Read())
                {

                    dt.Rows.Add(AdvisorData[0].ToString(), AdvisorData[1].ToString(), AdvisorData[2].ToString(), AdvisorData[3].ToString());

                }

            
            return dt;
        }

        private void NoGroupStd_Click(object sender, EventArgs e)
        {
            generate_atten_report(3,"UnGroupedStudents");
        }

        private void belowAvg_Click(object sender, EventArgs e)
        {
            generate_atten_report(4, "BelowAvg");
        }
        private DataTable BelowAvg()
        {
            var con = Configuration.getInstance().getConnection();



            DataTable dt = new DataTable();
            dt.Columns.Add("RegistrationNo", typeof(String));
            dt.Columns.Add("Name", typeof(String));
            dt.Columns.Add("ObtainedMarks", typeof(String));
            SqlCommand sql = new SqlCommand("USE ProjectA SELECT S.RegistrationNo, P.FirstName+' '+P.LastName AS NAME, Sum(GE.ObtainedMarks) as [Obtained Marks] FROM GroupEvaluation GE JOIN GroupStudent GS ON GS.GroupId = GE.GroupId JOIN Person P ON GS.StudentId = P.Id JOIN Student S ON GS.StudentId = S.Id Group by S.RegistrationNo,  P.FirstName+' '+P.LastName Having Sum(GE.ObtainedMarks) < (SELECT AVG(A.[total Marks]) FROM (SELECT SUM(ObtainedMarks) as [total Marks] FROM GroupEvaluation ge GROUP BY GroupId ) as A); ", con);
            SqlDataReader AdvisorData = sql.ExecuteReader();

            while (AdvisorData.Read())
            {

                dt.Rows.Add(AdvisorData[0].ToString(), AdvisorData[1].ToString(), AdvisorData[2].ToString());

            }


            return dt;
        }

        private void DeleteAdvisor_Click(object sender, EventArgs e)
        {

        }
    }
}
