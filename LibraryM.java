
import java.util.ArrayList;
import java.util.List;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Stallion
 */
public class Library {
     
  
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
       
Book bo=new Book();
Technicalbooks tech=new Technicalbooks();
magazine maga=new magazine();
Form1 f1=new Form1();

    }
     
private final List<magazine>mag=new ArrayList<magazine>();
private final  List<Technicalbooks>tech=new ArrayList<Technicalbooks>();
  private String libraryName;

    
     
  public boolean addMagazine(magazine b){
      boolean flag=false;
      
      return flag;
  }

  public String deleteMagazine(String isbn){
      return isbn;
  }
  
  public String editMagazine(String isbn,magazine b){
      return isbn;
  }
  
  public String searchMagazinebyTitle(String titleText){
      List<magazine>mag=new ArrayList<magazine>();
      return titleText;
  }
  
  public String searchMagazinebyAuthor(String authorText){
      List<magazine>mag=new ArrayList<magazine>();
      return authorText;
  }
  
  public boolean addTechnicalBook(Technicalbooks b){
      boolean flag=false;
      return flag;
  }
  
  public String deleteTechnicalBook(String isbn){
     return isbn;
  }
  
  public String editTechnicalBook(String isbn,Technicalbooks b){
      return isbn;
      
  }
  
  public String searchTechnicalBookByTitle(String titleText){
       List<Technicalbooks>mag=new ArrayList<Technicalbooks>();
      return titleText;
  }
  
  public String searchTechnicalBookByAuthor(String authorText){
       List<Technicalbooks>mag=new ArrayList<Technicalbooks>();
       return authorText;
  }
  
  public void savedata(){
      
  }
  
  public void loadData(){
      
  }
}


