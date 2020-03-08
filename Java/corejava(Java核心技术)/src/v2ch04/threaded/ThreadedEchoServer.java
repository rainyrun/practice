package v2ch04.threaded;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class ThreadedEchoServer {
	public static void main(String[] args) throws IOException {
		try(ServerSocket s = new ServerSocket(8189)){
		    int i = 1; // 线程序号
		    while(true){
		        Socket incoming = s.accept(); // 不停等待，直到有客户端连接到这个端口
		        System.out.println("Spawning " + i);
		        // 创建线程，为客户端服务
		        Runnable r = new ThreadEchoHandler(incoming);
		        Thread t = new Thread(r);
		        t.start();
		        i++;
		    }
		}
	}
}

class ThreadEchoHandler implements Runnable {
    private Socket incoming;
    public ThreadEchoHandler(Socket incoming){
        this.incoming = incoming;
    }
    public void run(){
        try(
            InputStream inStream = incoming.getInputStream(); // 得到输入流，收到客户端发出的信息
            OutputStream outStream = incoming.getOutputStream(); // 得到输出流，发送信息给客户端
            ){
            Scanner in = new Scanner(inStream, "UTF-8");
            PrintWriter out = new PrintWriter(new OutputStreamWriter(outStream, "UTF-8"), true); // 自动冲刷
            // 回显客户端输入的数据，输入BYE时关闭链接
            boolean done = false;
            while (!done && in.hasNextLine()) {
                String line = in.nextLine();
                out.println("Echo: " + line);
                if (line.trim().equals("BYE"))
                    done = true;
            }
        } catch(Exception e){
            e.printStackTrace();
        }
    }
}

