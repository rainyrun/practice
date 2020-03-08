package itheima.net;
import java.io.*;
import java.net.*;
import java.util.*;
/**
 * 需求
 * 1. 模拟用户登录。客户端输入用户名和密码，服务端交验用户名和密码是否正确。
 * 2. 服务端交验正确后，提示“登录成功”，否则提示“登录失败”
 */
public class Client {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("请输入用户名：");
		String name = br.readLine();
		System.out.println("请输入密码：");
		String password = br.readLine();
		
		//使用TCP协议创建链接
		Socket s = new Socket(InetAddress.getByName(null), 5678);
		//传送用户名和密码
		OutputStreamWriter os = new OutputStreamWriter(s.getOutputStream());
		os.write(name);
		os.write(password);
		//接收验证信息
		BufferedReader serverBr = new BufferedReader(new InputStreamReader(s.getInputStream()));
		System.out.println(serverBr.readLine());
		//关闭资源
		s.close();
	}
}
