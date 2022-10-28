/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package vehicle.hire.part.pkg1.step.pkg1;

public class Customer {
    String customerID;
    String surname;
    String firstName;
    String otherInitials;
    String title;

    public Customer( String surname, String firstName, String otherInitials, String title) {
        this.customerID = "unknown";
        this.surname = surname;
        this.firstName = firstName;
        this.otherInitials = otherInitials;
        this.title = title;
    }

    public Customer() {
    }
    public void printDetails()
    {
        System.out.print("Customer ID: "+ this.customerID);
        System.out.print("\tSurname: "+ this.surname);
        System.out.print("\tFirstname: "+ this.firstName);
        System.out.print("\tOther Initial: "+ this.otherInitials);
        System.out.print("\tTitle: "+ this.title);
            
    }
    public void readData(String scanner)
    {
        if (scanner.contains(",")) {
            String[] split = scanner.split(",");
           
            this.customerID = split[0];
            this.surname = split[1];
            this.firstName = split[2];
            this.otherInitials = split[3];
            this.title = split[4];
        }
    
    }
    public void generateCustomerID(String prefix, int digit)
    {
        this.customerID = prefix + Integer.toString(digit);
    }
    
    
}
