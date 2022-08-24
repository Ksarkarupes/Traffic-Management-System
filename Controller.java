package BackEnd;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.util.Scanner;

import com.fazecast.jSerialComm.*;

public class Controller {
	public static void main(String[] args) {
		SerialPort ports[]=SerialPort.getCommPorts();
		SerialPort port;		
		
		port=ports[1];
		if(port.openPort()) {
	       	 System.out.println("Open");
	        }else {
	       	 System.out.println("Closed");
	       	 return;
	        }
		Thread thread = new Thread() {
			@Override
			public void run() {
				try {
					Thread.sleep(100);
				} catch (Exception e) {
				}
				PrintWriter output = new PrintWriter(port.getOutputStream());
				while(true ) {
					DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
					LocalDateTime now = LocalDateTime.now();  
					String s = dtf.format(now);
					String time = s.substring(11,13);
					output.print(time);
					output.flush();
					System.out.print(time);
					try {
						Thread.sleep(1000);
					} catch (Exception e) {
					}
					
				}
			}
		};
		thread.start();
	}
}
