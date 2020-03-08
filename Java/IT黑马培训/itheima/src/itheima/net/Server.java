package itheima.net;
import java.io.*;
import java.net.*;

public class Server {
	public static void main(String[] args) throws IOException {
		//监听端口
		ServerSocket ss = new ServerSocket(5678);
		Socket s = ss.accept();
		//接受数据
		BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
		String name = br.readLine();
		String password = br.readLine();
		//返回数据
		boolean login = false;
		if(name.toString().equals("rainy") && password.toString().equals("123456")) {
			login = true;
		}
		OutputStreamWriter os = new OutputStreamWriter(s.getOutputStream());
		if(login) {
			os.write("登陆成功");
		}
		else {
			os.write("登陆失败");
		}
		s.close();
		ss.close();
	}
}
