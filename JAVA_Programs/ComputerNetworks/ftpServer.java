package ComputerNetworks;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class ftpServer {
   public static void main(String[] var0) throws Exception {
      Socket var1 = null;
      ServerSocket var2 = null;
      var2 = new ServerSocket(7777);
      var1 = var2.accept();
      BufferedReader var3 = new BufferedReader(new InputStreamReader(System.in));
      PrintStream var4 = new PrintStream(var1.getOutputStream());
      System.out.println("Enter File Name: ");
      String var5 = var3.readLine();
      File var7 = new File(var5);
      BufferedReader var8 = null;
      if (var7.exists()) {
         var8 = new BufferedReader(new FileReader(var5));

         String var6;
         while((var6 = var8.readLine()) != null) {
            var4.println(var6);
         }
      }

      var2.close();
      var4.close();
      var8.close();
    
    }
}

