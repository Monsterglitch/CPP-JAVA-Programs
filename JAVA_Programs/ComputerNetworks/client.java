package ComputerNetworks;

import java.io.*;

import java.net.*;

import java.util.*;

public class client {

    public static void main(String[] args) throws IOException{

        Socket s = null;

        try {

            s = new Socket("localhost", 6666);

            DataOutputStream dout = new DataOutputStream(s.getOutputStream());

            Scanner x = new Scanner(System.in);

            while (true) {

                System.out.println("TO SERVER: ");

                String data = x.nextLine();

                dout.writeUTF(data);

                if (data.equals("END")) {

                    System.out.println("Terminated");

                    break;

                }

                // dout.writeUTF(data);

                DataInputStream din = new DataInputStream(s.getInputStream());

                String s_data = din.readUTF();

                System.out.println("FROM SERVER: " + s_data);

            }

            x.close();
        }

        catch (Exception e) {

            System.out.println(e);

        }

        finally {
            s.close();
        }

    }

}
