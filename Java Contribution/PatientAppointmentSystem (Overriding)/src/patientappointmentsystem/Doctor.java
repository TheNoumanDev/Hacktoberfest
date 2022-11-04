package patientappointmentsystem;

public class Doctor extends Person {

    private String Qualification;
    private int CheckedPatients;
    private String Specialization;

    public Doctor(String Qualification, int CheckedPatients, String Specialization) {
        this.Qualification = Qualification;
        this.CheckedPatients = CheckedPatients;
        this.Specialization = Specialization;
    }

    public Doctor(int id, String name, String phoneNumber, String email, int age, String password, String CNIC, String Qualification, String Specialization) {
        super(id, name, phoneNumber, email, age, password, CNIC);
        this.Qualification = Qualification;
        this.Specialization = Specialization;
    }

    public Doctor() {
    }

    /**
     * @return the Qualification
     */
    public String getQualification() {
        return Qualification;
    }

    /**
     * @param Qualification the Qualification to set
     */
    public void setQualification(String Qualification) {
        this.Qualification = Qualification;
    }

    /**
     * @return the CheckedPatients
     */
    public int getCheckedPatients() {
        return CheckedPatients;
    }

    /**
     * @param CheckedPatients the CheckedPatients to set
     */
    public void setCheckedPatients(int CheckedPatients) {
        this.CheckedPatients = CheckedPatients;
    }

    /**
     * @return the Specialization
     */
    public String getSpecialization() {
        return Specialization;
    }

    /**
     * @param Specialization the Specialization to set
     */
    public void setSpecialization(String Specialization) {
        this.Specialization = Specialization;
    }

    @Override
    public void cancelAppointment(int AppointmentId) {
        PatientAppointmentSystem p = new PatientAppointmentSystem();
        p.Appoointmants.remove(AppointmentId);
        p.saveAppointments();
    }

}
