package v2ch04.server;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.Charset;
import java.util.Scanner;

/**
 * 创建一个服务端程序，监听端口8189。该程序接受客户端输入的内容，并回显到客户端。当输入BYE时，关闭链接。
 */
public class EchoServer {
	public static void main(String[] args) throws IOException {
		try ( // 创建链接
				ServerSocket s = new ServerSocket(8189);
				Socket incoming = s.accept();
				// 获取输入输出流
				InputStream inputStream = incoming.getInputStream();
				OutputStream outputStream = incoming.getOutputStream();
				// 封装成字符流
				Scanner in = new Scanner(inputStream, "UTF-8");
				PrintWriter out = new PrintWriter(outputStream, true, Charset.forName("UTF-8"));) {
			// 回显客户端输入的数据
			boolean done = false;
			while (!done && in.hasNextLine()) {
				String line = in.nextLine();
				out.println("Echo: " + line);
				if (line.trim().equals("BYE"))
					done = true;
			}
//			// 释放资源
//			in.close();
//			out.close();
//			inputStream.close();
//			outputStream.close();
//			incoming.close();
//			s.close();
		} // try
	}
}

/*
 * 关闭资源时，尽量使用try{}finally{}，或者使用带资源的try
 */
