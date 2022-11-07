/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package patientappointmentsystem;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class PatientAppointmentSystem {

    List<Doctor> DoctorList = new ArrayList<Doctor>();
    List<Patient> PatienListList = new ArrayList<Patient>();
    List<Appointment> Appoointmants = new ArrayList<Appointment>();

    public PatientAppointmentSystem() {
        try {
            loadPatient();
            loadDoctor();
            LoadAppointents();

        } catch (Exception e) {

        }
    }

    public void AddDoctor(Doctor D) {
        this.DoctorList.add(D);
    }
    public void AddPatient(Patient p) {
        this.PatienListList.add(p);
    }
    public void AddAppointment(Appointment A)
    {
        this.Appoointmants.add(A);
    }
    public void cancelAppointment(Appointment A){
        this.Appoointmants.remove(A);
    }
    public void deleteDoctor(Doctor D)
    {
        this.DoctorList.remove(D);
        
    }
    public void deletePatient(Patient p)
    {
        this.PatienListList.remove(p);
    }
    public List<Doctor> getDoctorList() {
        return DoctorList;
    }

    public List<Patient> getPatienListList() {
        return PatienListList;
    }

    public int getDoctorNewId() {
        if (DoctorList.size() == 0) {
            return 1;
        } else {
            return DoctorList.get(DoctorList.size() - 1).getId() + 2;
        }
    }

    public int getPatientNewId() {

        if (PatienListList.size() == 0) {
            return 2;
        } else {
//            System.err.println("anb");
            return PatienListList.get(PatienListList.size() - 1).getId() + 2;
        }
    }

    public int createAPpiyintmentID() {
        if (Appoointmants.size() == 0) {
            return 1;
        } else {
            return Appoointmants.get(Appoointmants.size() - 1).getAppointmenId() + 1;
        }
    }

    public void setAppointment(Appointment A) {
        A.setAppointmenId(createAPpiyintmentID());
        Appoointmants.add(A);
//        System.out.println(A.getAppointmenId());
        saveAppointments();
    }

    public boolean saveDoctor() {
        try (FileWriter fw = new FileWriter("Doctor.csv", false);) {

            for (int i = 0; i < DoctorList.size(); i++) {
                fw.write(DoctorList.get(i).getId() + "," + DoctorList.get(i).getName() + ","
                        + DoctorList.get(i).getPhoneNumber() + ","
                        + DoctorList.get(i).getEmail() + ","
                        + DoctorList.get(i).getAge() + ","
                        + DoctorList.get(i).getPassword() + ","
                        + DoctorList.get(i).getCNIC() + ","
                        + DoctorList.get(i).getQualification() + ","
                        + DoctorList.get(i).getCheckedPatients() + ","
                        + DoctorList.get(i).getSpecialization() + "\n");
            }
            fw.flush();

            fw.close();
            return true;

        } catch (Exception e) {
            return false;
        }
    }

    public boolean savePatients() {
        try (FileWriter fw = new FileWriter("Patient.csv", false);) {

            for (int i = 0; i < PatienListList.size(); i++) {
                fw.write(PatienListList.get(i).getId() + "," + PatienListList.get(i).getName() + ","
                        + PatienListList.get(i).getPhoneNumber() + ","
                        + PatienListList.get(i).getEmail() + ","
                        + PatienListList.get(i).getAge() + ","
                        + PatienListList.get(i).getPassword() + ","
                        + PatienListList.get(i).getCNIC() + ","
                        + PatienListList.get(i).getBloodGroup() + ","
                        + PatienListList.get(i).getPrescribedMed()
                        + "," + PatienListList.get(i).getDeseases() + "\n");
            }
            fw.flush();

            fw.close();
            return true;

        } catch (Exception e) {
            return false;
        }
    }

    public boolean saveAppointments() {
        try (FileWriter fw = new FileWriter("Appointments.csv", false);) {

            for (int i = 0; i < Appoointmants.size(); i++) {
                fw.write(Appoointmants.get(i).getAppointmenId() + ","
                        + Appoointmants.get(i).getDoctorId() + ","
                        + Appoointmants.get(i).getPatientId() + ","
                        + "\n");
            }
            fw.flush();

            fw.close();
            return true;

        } catch (Exception e) {
            return false;
        }
    }

    public void LoadAppointents() {
        String line = "";
//        System.err.println("Load Emp");
        try {

            BufferedReader br = new BufferedReader(new FileReader("Appointments.csv"));
            while ((line = br.readLine()) != null) {
                String[] s = line.split(",");
                Appointment a = new Appointment();

                a.setAppointmenId(Integer.parseInt(s[0]));
                a.setDoctorId(Integer.parseInt(s[1]));
                a.setPatientId(Integer.parseInt(s[2]));

                Appoointmants.add(a);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void loadDoctor() {
        String line = "";
//        System.err.println("Load Emp");
        try {

            BufferedReader br = new BufferedReader(new FileReader("Doctor.csv"));
            while ((line = br.readLine()) != null) {
                String[] doctor = line.split(",");
                Doctor d = new Doctor();
                d.setId(Integer.parseInt(doctor[0]));
                d.setName(doctor[1]);
                d.setPhoneNumber(doctor[2]);
                d.setEmail(doctor[3]);
                d.setAge(Integer.parseInt(doctor[4]));
                d.setPassword(doctor[5]);
                d.setCNIC(doctor[6]);
                d.setQualification(doctor[7]);
                d.setCheckedPatients(Integer.parseInt(doctor[8]));
                d.setSpecialization(doctor[9]);
//                System.out.print("123");
                DoctorList.add(d);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void loadPatient() {
        String line = "";
//        System.err.println("Load Em");
        try {

            BufferedReader br = new BufferedReader(new FileReader("Patient.csv"));
            while ((line = br.readLine()) != null) {
                String[] doctor = line.split(",");
                Patient d = new Patient();
                d.setId(Integer.parseInt(doctor[0]));
                d.setName(doctor[1]);
                d.setPhoneNumber(doctor[2]);
                d.setEmail(doctor[3]);
                d.setAge(Integer.parseInt(doctor[4]));
                d.setPassword(doctor[5]);
                d.setCNIC(doctor[6]);
                d.setBloodGroup(doctor[7]);
                d.setPrescribedMed(doctor[8]);
                d.setDeseases(doctor[9]);

                PatienListList.add(d);
//                System.out.print(d.getName());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
//        System.err.println(PatienListList.size());
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        (new Dashboard()).setVisible(true);

//        PatientAppointmentSystem p = new PatientAppointmentSystem();
//        Doctor d = new Doctor();
//        d.setId(p.getDoctorNewId());
//        p.DoctorList.add(d);
//        Doctor d2 = new Doctor();
//        d2.setId(p.getDoctorNewId());
//        p.DoctorList.add(d2);
//        System.out.println(d2.getId());
    }

}
