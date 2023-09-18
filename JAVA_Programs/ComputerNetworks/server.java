package ComputerNetworks;

import java.io.*;

import java.net.*;

import java.util.*;

public class server {

    public static void main(String[] args) throws IOException, EOFException {

        ServerSocket ss = null;

        Socket s = null; // ss.accept();

        try {

            ss = new ServerSocket(6666);

            s = ss.accept();

            while (true) {

                DataInputStream din = new DataInputStream(s.getInputStream());

                String data = din.readUTF();

                if (data.equals("END"))
                    break;

                System.out.println("FROM CLIENT: " + data);

                System.out.println("TO CLIENT");

                Scanner x = new Scanner(System.in);

                String s_data = x.nextLine();

                DataOutputStream dout = new DataOutputStream(s.getOutputStream());

                dout.writeUTF(s_data);

                x.close();
            }

            s.close();

            ss.close();

        }

        catch (Exception e) {

            System.out.println(e);

        }

        finally {

            ss.close();

            s.close();

        }

    }

}
