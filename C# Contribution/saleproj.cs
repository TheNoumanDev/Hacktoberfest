// Name: Umair Manzoor
// Username: Umair-Manzoor-47
// Favorite Language: C#



using System;
using System.Collections;
using System.Windows.Forms;
using System.ComponentModel;
using System.Drawing;

namespace Program_5
{
    
    class FirstWindow : Form{

        public Button signin, signup_Button;
        public Label header;
        public TextBox input1, input2;
        

        public FirstWindow(){
             init();
             addControls();
        }
        private void init(){
            this.Size = new Size(1000,700);
            this.Text = "Sales Project";
            this.Location = new Point(350,300);          
                        

            signin = new Button();
            signin.Text = "signin";
            signin.Location = new Point(250,100);
            signin.Size = new Size(100,30);
            signin.Click += new EventHandler(button1_click);

            signup_Button = new Button();
            signup_Button.Text = "SignUp";
            signup_Button.Size = new Size(100,30);
            signup_Button.Location = new Point(350,100);
            

            input1 = new TextBox();
            input1.Location = new Point(100, 100);
            input1.PlaceholderText = "Username: ";
            input1.Size = new Size(100,50);

            input2 = new TextBox();
            input2.Location = new Point(100, 150);
            input2.PlaceholderText = "Password";
            input2.Size = new Size(100,50);
            

            header = new Label();
            header.Text = "Sales Application!";
            header.Location = new Point(20,10);
            header.Size = new Size(80,80);
            
        }
        public void addControls(){
            this.Controls.Add(signin);
            this.Controls.Add(header);
            this.Controls.Add(input1);
            this.Controls.Add(input2);
            this.Controls.Add(signup_Button);
        }
        private void button1_click(object sender,EventArgs e){
            string username = input1.Text;
            string password = input2.Text;
            if(username == "admin" && password == "1234"){
            secondWindow obj = new secondWindow();
                obj.init();
                obj.Show();

            }else{
                input1.Text = "Good Bye!";
            }     
        

        }
    }

    class secondWindow: Form{
        public ArrayList product_list = new ArrayList();
        public Label loggedin; // name_label, id_label, price_label, stock_label;
        public Button add, save, view;

        public TextBox name, id, price, stock;            
    
    
    // A private constructor to restrict the object creation from outside
    public secondWindow()
    {


    }

    // A private static instance of the same class
    private static secondWindow  instance = null;

    public static secondWindow GetInstance()
    {
        // create the instance only if the instance is null
        if (instance == null)
        {
            instance = new secondWindow();
        }

        // Otherwise return the already existing instance
        return instance;
        }
        public void init(){
            
            this.Size = new Size(1050,760);
            this.Text = "Sales Project";
            this.Location = new Point(350,300);
            
            loggedin = new Label();
            loggedin.Text = "Welcome!";
            loggedin.Location = new Point(20,10);
            loggedin.Size = new Size(70,100);

            /*name_label = new Label();
            name_label.Text = "Name: ";
            name_label.Location = new Point(96, 54);*/

            name = new TextBox();
            name.Location = new Point(187, 51);
            name.PlaceholderText = "Product Name: ";
            name.Size = new Size(100,50);

            /*
            id_label = new Label();
            id_label.Text = "ID: ";
            id_label.Location = new Point(283, 108); */

            

            id = new TextBox();
            id.Location = new Point(100, 150);
            id.PlaceholderText = "Product ID: ";
            id.Size = new Size(100,50);

            price = new TextBox();
            price.Location = new Point(100, 200);
            price.PlaceholderText = "Price: ";
            price.Size = new Size(100,50);

            stock = new TextBox();
            stock.Location = new Point(100, 300);
            stock.PlaceholderText = "stock remaining";
            stock.Size = new Size(100,50);        
            
            add = new Button();
            add.Text = "Add Product";
            add.Location = new Point(250,100);
            add.Size = new Size(100,30);
            add.Click += new EventHandler(add_click);

            save = new Button();
            save.Text = "save Product";
            save.Location = new Point(300,100);
            save.Size = new Size(100,30);
            save.Visible = false;
            save.Click += new EventHandler(save_click);

            view = new Button();
            view.Text = "view Product";
            view.Location = new Point(300,200);
            view.Size = new Size(100,30);
            view.Click += new EventHandler(view_click);
            addControls();             

        }
        void addControls(){
            this.Controls.Add(loggedin);
            this.Controls.Add(add);
            this.Controls.Add(save);
            this.Controls.Add(view);

        }
        void view_click(object sender, EventArgs e){
            thirdWindow obj = new thirdWindow();
            obj.view();
            obj.Show();

        }
        void add_click(object sender, EventArgs e){
            add.Visible = false;
            view.Visible = false;
            save.Visible = true;
            loggedin.Text = "Add Product details:";
            this.Controls.Add(name);
            this.Controls.Add(id);
            this.Controls.Add(price);
            this.Controls.Add(stock);
            this.Controls.Add(save);
        }
        void save_click(object sender, EventArgs e){
            string Name = name.Text;
            int p_id = int.Parse(id.Text);
            float value = float.Parse(price.Text);
            int p_stock = int.Parse(stock.Text);

            Product obj = new Product();
            obj.setName(Name);
            obj.setID(p_id);
            obj.setPrice(value);
            obj.setStock(p_stock);
            product_list.Add(obj);
            this.SendToBack();

        }

    }
    class Product{
        private string name;
        private int id;
        private float price;
        private int stock;
        public void setName(string name){
            this.name = name;
        }
        public string getName(){
            return this.name;
        }
        public void setID(int id){
            this.id = id;
        }
        public int getid(){
            return this.id;
        }
        public void setPrice(float price){
            this.price = price;
        }
        public float getPrice(){
            return this.price;
        }
        public void setStock(int stock){
            this.stock = stock;
        }
        public int getStock(){
            return this.stock;
        }   
    }
    class thirdWindow: Form{
        public DataGridView grid;
        public thirdWindow(){
            init();
        }

        void init(){
            
            grid = new DataGridView();
            grid.Location = new Point(200,200);
            grid.Size = new Size(500,250);
            grid.ColumnCount = 4;
            grid.Columns[0].Name = "Name";
            grid.Columns[1].Name = "ID";
            grid.Columns[2].Name = "Price";
            grid.Columns[3].Name = "Stock";
            this.Controls.Add(grid);
        }
        public void view(){
            secondWindow obj = new secondWindow();
            ArrayList products = obj.product_list;
            for (int i=0; i<products.Count;i++){
                    Product P = (Product) products[i]; //conversion
                    string name = P.getName();
                    string id = P.getid().ToString();
                    string price = P.getPrice().ToString();
                    string stock = P.getStock().ToString();
                    populateGridView(name, id, price, stock);
                }
        }
        private void populateGridView(string name, string id, string price, string stock){
            String[] row= {name, id, price, stock};
            grid.Rows.Add(row);  

        }
        

    }            
    class Program
    {
        static void Main(string[] args)
        {         
            FirstWindow firstWindow = new FirstWindow();
            Application.EnableVisualStyles();
            Application.Run(firstWindow);

        }
    }
   }

