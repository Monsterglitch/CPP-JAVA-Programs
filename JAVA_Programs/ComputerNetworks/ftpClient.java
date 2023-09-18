package ComputerNetworks;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class ftpClient {
   public static void main(String[] var0) throws Exception {
      InetAddress var1 = InetAddress.getLocalHost();
      Socket var2 = new Socket(var1, 7777);
      System.out.println("Enter File Name: ");
      BufferedReader var5 = new BufferedReader(new InputStreamReader(System.in));
      String var3 = var5.readLine();
      new File(var3);
      PrintWriter var7 = new PrintWriter(new FileWriter(var3));
      BufferedReader var8 = new BufferedReader(new InputStreamReader(var2.getInputStream()));

      String var4;
      while((var4 = var8.readLine()) != null) {
         var7.println(var4);
      }

      var7.close();
      var2.close();
   }
}

