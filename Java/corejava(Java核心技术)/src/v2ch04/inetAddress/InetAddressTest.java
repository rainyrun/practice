package v2ch04.inetAddress;

import java.net.InetAddress;
import java.net.UnknownHostException;

/**
 * 在命令行接受一个主机名的参数，打印出该主机名下所有的ip地址。如果没有参数，则打印本机的ip地址
 */
public class InetAddressTest {
	public static void main(String[] args) throws UnknownHostException {
		if(args.length > 0) {
			String host = args[0];
			InetAddress[] addresses = InetAddress.getAllByName(host);
			for (InetAddress a : addresses) {
				System.out.println(a);
			}
		} else {
			InetAddress localAddress = InetAddress.getLocalHost();
			System.out.println(localAddress);
		}
	}
}
