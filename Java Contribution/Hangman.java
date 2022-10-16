import java.util.Random;
import java.util.Scanner;
import java.lang.*;
public class Hangman {
    static String[] wordCollection;
    static Random r;
    static int guesses;
    static int warning;
    static String guessedWord;
    final static String compPick;
    Hangman(){

        this.wordCollection = new String[]  {"banana", "apple", "mango", "pinapple", "grapefruit", "kiwi", "custardapple", "dragonfruit", "coconut", "strawberry", "blueberry", "melon", "tangerine", "apricot", "peach", "orange", "cherry", "grape", "watermelon", "pear"};
        this.r = new Random();
        this.compPick = this.wordCollection[(this.r).nextInt(20)];
        this.guesses = (int)(1.5 * ((this.compPick).length()));
        this.warning = 4;
        this.guessedWord = "";
        for (int i=0;i<(this.compPick).length();i++){
            this.guessedWord = this.guessedWord + "_";
        }
    }
    public String totalAlpha(){
        String letters = new String();
        for (char c = 'a';c<='z';++c){
            letters +=c;
        }
        return letters;
    }
    public String availableLetters(String c){
        String a ="";
        for (int i=0;i<totalAlpha().length();i++){
            if (c.contains(String.valueOf(totalAlpha().charAt(i)))){
                continue;
            } else {
                a = a + (totalAlpha().charAt(i));
            }
        }
        return a;
    }
    public Boolean isInPick(char letter) {
        if ((this.compPick).contains(String.valueOf(letter))){
            return true;
        }
        return false;
    }
    public void updateGuessed(char letter, int loc) {
        String abc = this.guessedWord;
        this.guessedWord = ((abc).substring(0,loc))+(letter)+((abc).substring(loc+1));

    }
    public void PrintupdateGuessed() {
        System.out.println(">>>  "+this.guessedWord);

    }
    public static void play() {
        Scanner sc = new Scanner(System.in);
        System.out.println("----------_....  HANGMAN  ...._----------");
        System.out.println(compPick);
        System.out.println("There are "+(this.compPick).length()+" Characters in my word! ");
        while ((this.guesses)>0){
            System.out.println("-----------------------------------");
            System.out.println("Total Guesses Left: "+(this.guesses));


            System.out.println("Available letters: "+availableLetters(this.guessedWord));
            System.out.print("Enter Word: ");
            char input = Character.toLowerCase(sc.next().charAt(0));
            if (Character.isAlphabetic(input)){
                System.out.print("");
                } else {
                System.out.println("Oops! Pls enter an alphabet ");
                this.guesses += 1;
                this.warning -= 1;
                if ((this.warning)>=0){
                    System.out.println("Total Warnings Left: "+this.warning);
                } else {
                    System.out.println("Total Warnings Left: 0");
                    this.warning = 0;
                }
                if (this.warning == 0){
                    System.out.println("All warnings Used!");
                    this.guesses -= 1;


            }
            }
            boolean tp = true;
            if (((this.guessedWord).contains(String.valueOf(input)))){
                System.out.println("Oops you repeated a letter!");
                this.warning -= 1;
                if ((this.warning)>=0){
                    System.out.println("Total Warnings Left: "+this.warning);
                } else {
                    System.out.println("Total Warnings Left: 0");
                    this.warning = 0;
                }
                tp = false;

                if ((this.warning) == 0){
                    System.out.println("All warnings Used!");


                } else {
                    this.warning -= 1;
                    this.guesses += 1;
                }
            }

            if (isInPick(input) == true){
                if (tp){
                    System.out.println("Good Guess!");
                }
                for (int i=0;i<(this.compPick).length();i++){
                    String any = input+"";
                    String oye = (this.compPick).charAt(i) + "";
                    if (any.equals(oye)){

                        updateGuessed(input,i);

                        if ((this.guessedWord).equals(compPick)){
                            this.guesses = 0;
                            System.out.println("-----------------------------------");
                            System.out.println("<<< ------  You Won ------ >>>");
                        }

                    }
                    else {

                        continue;
                    }

                }


            } else {
                System.out.println("Wrong Guess!");
            }
            PrintupdateGuessed();
            this.guesses = this.guesses - 1;


            if (guesses == 0){
                System.out.println("You are out of guesses!");
                System.out.println("You Failed! ");
                System.out.println("-----------------------------------");
                break;
            }



        }
        System.out.println("-----------------------------------");


    }

    public static void main(String args[]) {
        Hangman h = new Hangman();
        h.play();
    }
}
