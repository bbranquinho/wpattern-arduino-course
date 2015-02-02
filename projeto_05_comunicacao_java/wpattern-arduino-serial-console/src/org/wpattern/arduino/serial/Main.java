package org.wpattern.arduino.serial;

import java.util.Scanner;

public class Main {

	private static Scanner scanner = new Scanner(System.in);

	// -Djava.library.path=C:/Programas/rxtx
	public static void main(String[] args) throws Exception {
		System.out.println("Application started.");

		Serial serial = new Serial();

		serial.initialize();

		while (true) {
			// Leitura pelo teclado dos dados.
			String message = scanner.next();

			// Envio dos dados para o Arduino.
			serial.sendMessage(message);
		}
	}

}
