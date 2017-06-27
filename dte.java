import java.util.Scanner;

public class dte {
   public static void main(String args[]){
	   System.out.println("         Download Time Estimator:\n");
	   Scanner input = new Scanner(System.in);
	   System.out.println("Enter Size of file(MB):");
	   try { double size = input.nextDouble(); 
	   System.out.println("Choose unit of your download speed:\n"+
	   "1)Kilobyte(KB)\n"+
	   "2)Megabyte(MB)\n"+
	   "3)GigaByte(GB)\n"+
	   "4)Kibibyte(KiB)\n"+	   
	   "5)Mebibyte(MiB)\n"+	   
	   "6)Gibibyte(GiB)\n"+
	   "7)Kilobit(Kb)\n"+
	   "8)Megabit(Mb)\n"+
	   "9)Gigabit(Gb)\n");
	   String unit = input.next();
	   System.out.println("Enter Speed:");
	   double speed = input.nextDouble();
	   if (unit.equals("1") || unit.equals("KB")) {
		   double Speed = speed/1000;	   
		   double time = size/Speed;
		   if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: "+hours+" hours "+mins+" mins "+secs+" secs.");
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: " + mins + " mins " + secs + " secs.");
		   }
		   else {
			   int secs = (int) time;
		   System.out.println("Estimated Time: " + secs + " secs.");}
       } 
	   else if (unit.equals("2") || unit.equals("MB")) {	   
		   double time = size/speed;
		   if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: "+hours+" hours "+mins+" mins "+secs+" secs.");
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: " + mins + " mins " + secs + " secs.");
		   }
		   else {
			   int secs = (int) time;
		   System.out.println("Estimated Time: " + secs + " secs.");}
       }
	   else if (unit.equals("3") || unit.equals("GB")) {
		   double Speed = speed*1000;	   
		   double time = size/Speed;
		   if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: "+hours+" hours "+mins+" mins "+secs+" secs.");
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: " + mins + " mins " + secs + " secs.");
		   }
		   else {
			   int secs = (int) time;
		   System.out.println("Estimated Time: " + secs + " secs.");}
       }
	   else if (unit.equals("4") || unit.equals("KiB")) {
		   double Speed = speed*0.001024;	   
		   double time = size/Speed;
		   if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: "+hours+" hours "+mins+" mins "+secs+" secs.");
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: " + mins + " mins " + secs + " secs.");
		   }
		   else {
			   int secs = (int) time;
		   System.out.println("Estimated Time: " + secs + " secs.");}
       }
	   else if (unit.equals("5") || unit.equals("MiB")) {
		   double Speed = speed*1.048576;	   
		   double time = size/Speed;
		   if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: "+hours+" hours "+mins+" mins "+secs+" secs.");
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: " + mins + " mins " + secs + " secs.");
		   }
		   else {
			   int secs = (int) time;
		   System.out.println("Estimated Time: " + secs + " secs.");}
       }
	   else if (unit.equals("6") || unit.equals("GiB")) {
		   double Speed = speed*1073.741824;	   
		   double time = size/Speed;
		   if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: "+hours+" hours "+mins+" mins "+secs+" secs.");
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: " + mins + " mins " + secs + " secs.");
		   }
		   else {
			   int secs = (int) time;
		   System.out.println("Estimated Time: " + secs + " secs.");}
       }
	   else if (unit.equals("7") || unit.equals("Kb")) {
		   double Speed = speed*0.000125;	   
		   double time = size/Speed;
		   if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: "+hours+" hours "+mins+" mins "+secs+" secs.");
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: " + mins + " mins " + secs + " secs.");
		   }
		   else {
			   int secs = (int) time;
		   System.out.println("Estimated Time: " + secs + " secs.");}
       }
	   else if (unit.equals("8") || unit.equals("Mb")) {
		   double Speed = speed*0.125;	   
		   double time = size/Speed;
		   if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: "+hours+" hours "+mins+" mins "+secs+" secs.");
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: " + mins + " mins " + secs + " secs.");
		   }
		   else {
			   int secs = (int) time;
		   System.out.println("Estimated Time: " + secs + " secs.");}
       }
	   else if (unit.equals("9") || unit.equals("Gb")) {
		   double Speed = speed*125;	   
		   double time = size/Speed;
		   if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: "+hours+" hours "+mins+" mins "+secs+" secs.");
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   System.out.println("Estimated Time: " + mins + " mins " + secs + " secs.");
		   }
		   else {
			   int secs = (int) time;
		   System.out.println("Estimated Time: " + secs + " secs.");}
       }
	   else {   	   
           System.out.println("Invalid choice!");
           }  
	   }
	   catch (Exception e) {
		   System.out.println("Invalid Input!");
	   } 	   
       }  
   }
