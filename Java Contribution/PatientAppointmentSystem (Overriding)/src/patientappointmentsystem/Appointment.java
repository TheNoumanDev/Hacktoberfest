package patientappointmentsystem;

import java.util.ArrayList;
import java.util.List;

public class Appointment {

    private int appointmenId;
    private int doctorId;
    private int patientId;

    private String prescribedMedicines;

    /**
     * @return the appointmenId
     */
    public int getAppointmenId() {
        return appointmenId;
    }

    /**
     * @param appointmenId the appointmenId to set
     */
    public void setAppointmenId(int appointmenId) {
        this.appointmenId = appointmenId;
    }

    /**
     * @return the doctorId
     */
    public int getDoctorId() {
        return doctorId;
    }

    /**
     * @param doctorId the doctorId to set
     */
    public void setDoctorId(int doctorId) {
        this.doctorId = doctorId;
    }

    /**
     * @return the patientId
     */
    public int getPatientId() {
        return patientId;
    }

    /**
     * @param patientId the patientId to set
     */
    public void setPatientId(int patientId) {
        this.patientId = patientId;
    }

    /**
     * @return the prescribedMedicines
     */
    public String getPrescribedMedicines() {
        return prescribedMedicines;
    }

    /**
     * @param prescribedMedicines the prescribedMedicines to set
     */
    public void setPrescribedMedicines(String prescribedMedicines) {
        this.prescribedMedicines = prescribedMedicines;
    }

}
