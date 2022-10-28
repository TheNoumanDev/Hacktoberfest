/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package vehicle.hire.part.pkg1.step.pkg1;

import java.io.FileNotFoundException;
import java.util.Random;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;



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


public class Vehicle {
    String group;
    String vehID;
    String regNo;
    String make;
    String  model;
    boolean airCon;
    double engineSize;
    String fuelType;
    String gearbox;
    String transmission;
    int mileage;
    String dateFirstRegistered;
    
    
    
    public Vehicle() {
    }
    public Vehicle(String group, String vehID, String regNo, String make) {
        this.group = group;
        this.vehID = vehID;
        this.regNo = regNo;
        this.make = make;
      

    }

    public Vehicle(String group, String vehID, String regNo, String make, String model, boolean airCon, double engineSize, String fuelType, String gearbox, String transmission, int mileage, String dateFirstRegistered) {
        this.group = group;
        this.vehID = vehID;
        this.regNo = regNo;
        this.make = make;
        this.model = model;
        this.airCon = airCon;
        this.engineSize = engineSize;
        this.fuelType = fuelType;
        this.gearbox = gearbox;
        this.transmission = transmission;
        this.mileage = mileage;
        this.dateFirstRegistered = dateFirstRegistered;
    }
    
    public void printDetails()
    {
        System.out.println(this.make + this.model + "Group: "+this.group +"Vehicle Id: "+this.vehID );
        System.out.println("Air conditioning/Climate Control:"+ this.airCon);
        System.out.println("Engine Size: "+ this.engineSize + "\tFuel: "+ this.fuelType);
        System.out.println("Gearbox: "+ this.gearbox + "\tTransmission: "+ this.transmission);
        System.out.println("Mileage: "+ this.mileage+ "Date first registered: "+this.dateFirstRegistered);
        System.out.println("Registeration Number"+this.regNo);
        

        
    }
    
    public void readData(String scanner)
    {
        if (scanner.contains(",")) {
            String[] split = scanner.split(",");
            
            this.group = split[0];
            this.vehID = split[1];
            
            this.regNo = split[2];
            this.make = split[3];
            this.model = split[4];
            
            this.airCon = Boolean.parseBoolean(split[5].replaceAll(" ", ""));
            this.engineSize = Double.parseDouble(split[6]);
            this.fuelType = split[7];
            this.gearbox = split[8];
            this.transmission = split[9];
          
            this.mileage = Integer.parseInt(split[10].replaceAll(" ", ""));
            
            this.dateFirstRegistered = split[11];
        }
             
    }
    
    
    
    
}

public class Car extends Vehicle{
    
    String bodyType;
    int noOfDoors;
    int noOfSeats;
    
    @Override
    public void printDetails()
    {
        System.out.println(this.make +" "+ this.model + "Group: "+this.group +"Vehicle Id: "+this.vehID );
        System.out.println("Air conditioning/Climate Control:"+ this.airCon);
        System.out.println("Engine Size: "+ this.engineSize + "\tFuel: "+ this.fuelType);
        System.out.println("Gearbox: "+ this.gearbox + "\tTransmission: "+ this.transmission);
        System.out.println("Mileage: "+ this.mileage+ "Date first registered: "+this.dateFirstRegistered);
        System.out.println("Registeration Number"+ this.regNo);
        System.out.println("Body Type: "+this.bodyType);
        System.out.println("No of Doors: "+this.noOfDoors);
        System.out.println("No of Seats: "+this.noOfSeats);
    }
    
    @Override
    public void readData(String scanner)
    {
        if (scanner.contains(",")) {
            String[] split = scanner.split(",");
            
            this.group = split[0];
            this.vehID = split[1];
            this.regNo = split[2];
            this.make = split[3];
            this.model = split[4];
            this.airCon = Boolean.parseBoolean(split[5].replaceAll(" ", ""));
            this.engineSize = Double.parseDouble(split[6].replaceAll(" ", ""));
            this.fuelType = split[7];
            this.gearbox = split[8];
            this.transmission = split[9];
            this.mileage = Integer.parseInt(split[10].replaceAll(" ", ""));
            this.dateFirstRegistered = split[11];
            
            this.bodyType = split[12];
            this.noOfDoors = Integer.parseInt(split[13].replaceAll(" ", ""));
            this.noOfSeats = Integer.parseInt(split[14].replaceAll(" ", ""));
            
            
        }
        else {
            System.err.println("Error in reading car data...");
        }
             
    }
    
    
}


public class Commercial extends Vehicle{
    int payload;
    
}

public class Truck extends Commercial{
    String attributes;
    
    
    @Override
    public void printDetails()
    {
        System.out.println(this.make +" "+ this.model + "Group: "+this.group +"Vehicle Id: "+this.vehID );
        System.out.println("Air conditioning/Climate Control:"+ this.airCon);
        System.out.println("Engine Size: "+ this.engineSize + "\tFuel: "+ this.fuelType);
        System.out.println("Gearbox: "+ this.gearbox + "\tTransmission: "+ this.transmission);
        System.out.println("Mileage: "+ this.mileage+ "Date first registered: "+this.dateFirstRegistered);
        System.out.println("Registeration Number: "+ this.regNo);
        System.out.println("Playload: "+this.payload);
        System.out.println("Additional Attributes: "+this.attributes);
    }
    
    @Override
    public void readData(String scanner)
    {
        if (scanner.contains(",")) {
            String[] split = scanner.split(",");
            
            this.group = split[0];
            this.vehID = split[1];
            this.regNo = split[2];
            this.make = split[3];
            this.model = split[4];
            this.airCon = Boolean.parseBoolean(split[5].replaceAll(" ", ""));
            this.engineSize = Double.parseDouble(split[6].replaceAll(" ", ""));
            this.fuelType = split[7];
            this.gearbox = split[8];
            this.transmission = split[9];
            this.mileage = Integer.parseInt(split[10].replaceAll(" ", ""));
            this.dateFirstRegistered = split[11];
            
            this.payload = Integer.parseInt(split[12].replaceAll(" ", ""));
            String s = "";
            for(int i = 13;i<split.length;i++)
            {
                s = s+split[i];
                if(i < split.length-1)
                {
                    s = s+",";
                }
            }
            this.attributes = s;
           
            
            
        }
        else {
            System.err.println("Error in reading truck data...");
        }
             
    }
}
    
    



public class Van extends Commercial {

    double loadVolume;
    boolean slidingSideDoor;
    
    
    @Override
    public void printDetails()
    {
        System.out.println(this.make +" "+ this.model + "Group: "+this.group +"Vehicle Id: "+this.vehID );
        System.out.println("Air conditioning/Climate Control:"+ this.airCon);
        System.out.println("Engine Size: "+ this.engineSize + "\tFuel: "+ this.fuelType);
        System.out.println("Gearbox: "+ this.gearbox + "\tTransmission: "+ this.transmission);
        System.out.println("Mileage: "+ this.mileage+ "Date first registered: "+this.dateFirstRegistered);
        System.out.println("Registeration Number"+ this.regNo);
        System.out.println("Playload"+this.payload);
        
        System.out.println("Load Volume: "+ this.loadVolume);
        System.out.println("Sliding Side Door: "+ this.slidingSideDoor);
    }
    @Override
    public void readData(String scanner)
    {
        if (scanner.contains(",")) {
            String[] split = scanner.split(",");
            
            this.group = split[0];
            this.vehID = split[1];
            this.regNo = split[2];
            this.make = split[3];
            this.model = split[4];
            this.airCon = Boolean.parseBoolean(split[5].replaceAll(" ", ""));
            this.engineSize = Double.parseDouble(split[6].replaceAll(" ", ""));
            this.fuelType = split[7];
            this.gearbox = split[8];
            this.transmission = split[9];
            this.mileage = Integer.parseInt(split[10].replaceAll(" ", ""));
            this.dateFirstRegistered = split[11];
            
            this.payload = Integer.parseInt(split[12].replaceAll(" ", ""));
            this.loadVolume = Double.parseDouble(split[13].replaceAll(" ", ""));
            this.slidingSideDoor = Boolean.parseBoolean(split[14].replaceAll(" ", ""));
           
            
            
        }
        else {
            System.err.println("Error in reading van data...");
        }
             
    }
}


public class Test {

    public Test() throws FileNotFoundException {
      
       
        ReservationSystem rs = new ReservationSystem();
        
        Scanner in = new Scanner(System.in);
        char n = 'x';
        do{
            menu();
            n = in.next().charAt(0);
            
            if (n == '1') {
                
                rs.readVehicleData();
                rs.printAllVehicles();
        
                
            }
            else if(n == '2')
            {
                rs.readCustomerData();
                
            }
            else if(n == '3')
            {
                rs.storeCustomer();
            }
            else if(n == '4')
            {
                rs.printAllCustomers();
            }
            else if(n == '5')
            {
                rs.writeCustomerData();
            }
            else if(n == '0')
            {
                System.out.println("System has been closed...");
            }
            else{
                System.err.println("Invalid Input...");
                
            }
            
            
        }while(n!='0');
       
        
        
        
    }
    private void menu()
    {
        System.out.println("Enter 1 to test Vehicle Data");
        System.out.println("Enter 2 to load Customer Data Data");
        System.out.println("Enter 3 to Assign ID to Customer Data Data");
        System.out.println("Enter 4 to Displey Customer Data Data");
        System.out.println("Enter 5 to Save Customer Data Data");
        System.out.println("Enter 0 to Exit");
        System.out.print("Input: ");
        
        
    }
    
    
    
}



public class ReservationSystem {

    private List<Vehicle> vehicleList = new ArrayList<Vehicle>();
    private List<Customer> customerList = new ArrayList<Customer>();

    public void storeVehicle(Vehicle v) {
        vehicleList.add(v);
    }

    public void printAllVehicles() {
        for (Vehicle vehicle : vehicleList) {
            vehicle.printDetails();
            System.out.println();
        }
    }

    public void readVehicleData() {

        boolean carType = false, vanType = false, truckType = false;

        try {
            JFileChooser ch = new JFileChooser();
            Scanner scanner = null;

            if (ch.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
                File selectedFile = ch.getSelectedFile();
                scanner = new Scanner(selectedFile);

                while (scanner.hasNextLine()) {
                    String s = scanner.nextLine().toString();

                    if (s.isEmpty()) {
                    } else if (s.charAt(0) == '/' && s.charAt(1) == '/') {

                    } else if (s.charAt(0) == '[') {
                        if (s.contains("Car data")) {
                            carType = true;
                            vanType = false;
                            truckType = false;
                        } else if (s.contains("van data")) {
                            carType = false;
                            vanType = true;
                            truckType = false;
                        } else if (s.contains("Truck data")) {
                            carType = false;
                            vanType = false;
                            truckType = true;
                        }
                    } else {
                        if (carType) {
                            Car c = new Car();
                            c.readData(s);
                            vehicleList.add(c);

                        } else if (vanType) {
                            Van van = new Van();
                            van.readData(s);
                            vehicleList.add(van);
                        } else if (truckType) {
                            Truck t = new Truck();
                            t.readData(s);
                            vehicleList.add(t);
                        }

                    }

                }
//                System.err.println(vehicleList.size());

            }
        } catch (Exception e) {
            System.err.println("Exception Occure...");
        }
    }

    ////////////Part 3 (Cuustomer)//////////////
    public void storeCustomer() {

        for (Customer customer : customerList) {
            int id = garnerateRendomeSixDigit();
            while (!gernerateUniqueID(id)) {
                id = garnerateRendomeSixDigit();
            }
            customer.generateCustomerID("AB", id);

        }

    }

    private int garnerateRendomeSixDigit() {
        Random rand = new Random();
        String num = "";
        for (int i = 1; i <= 6; i++) {
            int random = rand.nextInt(10);
            num = num + Integer.toString(random);
        }
        return Integer.parseInt(num);

    }

    private boolean gernerateUniqueID(int id) {
        for (Customer customer : customerList) {
            if (customer.customerID.contains("-")) {
                String[] split = customer.customerID.split("-");
                if (split[1].equals(Integer.toString(id))) {
                    return false;
                }

            }
        }
        return true;
    }

    public void printAllCustomers() {
        for (Customer customer : customerList) {
            customer.printDetails();
            System.out.println();

        }
    }

    public void readCustomerData() {

        try {
            JFileChooser ch = new JFileChooser();
            Scanner scanner = null;

            if (ch.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
                File selectedFile = ch.getSelectedFile();
                scanner = new Scanner(selectedFile);

                while (scanner.hasNextLine()) {
                    String s = scanner.nextLine().toString();

                    if (s.isEmpty()) {
                    } else if (s.charAt(0) == '/' && s.charAt(1) == '/') {
                    } else {
                        Customer c = new Customer();
                        c.readData(s);
                        customerList.add(c);

                    }

                }

            }
        } catch (Exception e) {
            System.err.println("Exception Occure...");
        }
    }

    public void writeCustomerData() {

        JFileChooser fileChooser = new JFileChooser();
        if (fileChooser.showSaveDialog(null) == JFileChooser.APPROVE_OPTION) {
            File file = fileChooser.getSelectedFile();
            try {
                String path = file.getPath() + ".txt";
                file = new File(path);
                FileWriter filewriter = new FileWriter(file.getPath(), true);
                BufferedWriter buff = new BufferedWriter(filewriter);
                PrintWriter writer = new PrintWriter(buff);
//                writer.write("//writer data is customerID, surname, firstName, otherInitials, title\n\n");
                 String s = "" ;
                for (Customer customer : customerList) {
                   s = s + customer.customerID + "," + customer.surname + "," + customer.firstName + ","+ customer.otherInitials + ","+ customer.title + "\n";
                    

                }
                writer.write(s);
                writer.flush();
                writer.close();
            } catch (IOException e1) {
                e1.printStackTrace();
            }
        }
//        PrintWriter writer = null;
//        try {
//
//            writer = new PrintWriter(new File("Written_Customer_Data.txt"));
//
//            writer.write("// data is customerID, surname, firstName, otherInitials, title\n\n");
//            for (Customer customer : customerList) {
//                String s = String.format(customer.customerID + "," + customer.surname + "," + customer.firstName + ",", customer.otherInitials + ",", customer.title + "\n");
//                writer.write(s);
//
//            }
//
//        } catch (FileNotFoundException ex) {
//
//            Logger.getLogger(ReservationSystem.class.getName()).log(Level.SEVERE, null, ex);
//            System.err.println("File not found");
//
//        }
//        writer.flush();
//        writer.close();
    }

}


public class VehicleHirePart1Step2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        Test t = new Test();

    }
}
