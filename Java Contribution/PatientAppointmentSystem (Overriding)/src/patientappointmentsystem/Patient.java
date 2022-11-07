/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package patientappointmentsystem;

import java.util.List;
import java.util.ArrayList;

/**
 *
 * @author Nabeel Yousaf
 */
public class Patient extends Person{
    protected String BloodGroup;
    private String deseases ;
    private String prescribedMed;

    public Patient() {
    }

    
   public Patient( int id, String name, String phoneNumber, String email, int age, String password, String CNIC, String BloodGroup) {
        super(id, name, phoneNumber, email, age, password, CNIC);
        this.BloodGroup = BloodGroup;
    }

    public String getBloodGroup() {
        return BloodGroup;
    }

    public void setBloodGroup(String BloodGroup) {
        this.BloodGroup = BloodGroup;
    }

    /**
     * @return the deseases
     */
    public String getDeseases() {
        return deseases;
    }

    /**
     * @param deseases the deseases to set
     */
    public void setDeseases(String deseases) {
        this.deseases = deseases;
    }

    /**
     * @return the prescribedMed
     */
    public String getPrescribedMed() {
        return prescribedMed;
    }

    /**
     * @param prescribedMed the prescribedMed to set
     */
    public void setPrescribedMed(String prescribedMed) {
        this.prescribedMed = prescribedMed;
    }

    @Override
    public void cancelAppointment(int AppointmentId) {
        
        PatientAppointmentSystem p = new PatientAppointmentSystem();
        p.Appoointmants.remove(AppointmentId);
        p.saveAppointments();
    }
    
    
    
    
            
    
    
    
    
}
