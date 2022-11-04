
package patientappointmentsystem;


public class Person {

    int id;
    String name;
    String phoneNumber;
    String email;
    int age;
    String password;
    String CNIC;

    public Person() {
    }

    public Person(int id, String name, String phoneNumber, String email, int age, String password, String CNIC) {
        this.id = id;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.email = email;
        this.age = age;
        this.password = password;
        this.CNIC = CNIC;
    }

    /**
     * @return the id
     */
    public int getId() {
        return id;
    }

    /**
     * @param id the id to set
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return the phoneNumber
     */
    public String getPhoneNumber() {
        return phoneNumber;
    }

    /**
     * @param phoneNumber the phoneNumber to set
     */
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    /**
     * @return the email
     */
    public String getEmail() {
        return email;
    }

    /**
     * @param email the email to set
     */
    public void setEmail(String email) {
        this.email = email;
    }

    /**
     * @return the age
     */
    public int getAge() {
        return age;
    }

    /**
     * @param age the age to set
     */
    public void setAge(int age) {
        this.age = age;
    }

    /**
     * @return the password
     */
    public String getPassword() {
        return password;
    }

    /**
     * @param password the password to set
     */
    public void setPassword(String password) {
        this.password = password;
    }

    /**
     * @return the CNIC
     */
    public String getCNIC() {
        return CNIC;
    }

    /**
     * @param CNIC the CNIC to set
     */
    public void setCNIC(String CNIC) {
        this.CNIC = CNIC;
    }
    
    
    public void cancelAppointment(int AppointmentId){
        PatientAppointmentSystem p = new PatientAppointmentSystem();
        
        for (int i = 0; i < p.Appoointmants.size(); i++) {
            if(p.Appoointmants.get(i).getAppointmenId() == AppointmentId)
            {
                p.Appoointmants.remove(i);
                p.saveAppointments();
                
            
            }
        }
    }
}
