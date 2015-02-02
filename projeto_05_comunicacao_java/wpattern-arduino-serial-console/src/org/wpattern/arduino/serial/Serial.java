package org.wpattern.arduino.serial;

import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;

public class Serial implements SerialPortEventListener {
	
	// Timeout esperado para a abertura da comunicacao.
	private static final int TIME_OUT = 2000;
	
	// Frequencia de comunicacao da porta serial.
	private static final int DATA_RATE = 9600;
	
	// Porta que sera aberta.
	private static final String COM = "COM9";

	// Porta serial.
	private SerialPort serialPort;

	// Buffer de leitura.
	private BufferedReader input;

	// Buffer de escrita.
	private OutputStream output;

	public void initialize() throws Exception {
		// Criada a porta serial.
		CommPortIdentifier portId = CommPortIdentifier.getPortIdentifier(COM);

		// Abrindo a comunicacao com a porta serial.
		serialPort = (SerialPort) portId.open(this.getClass().getName(), TIME_OUT);

		// Parametros de comunicacao com a porta serial.
		serialPort.setSerialPortParams(DATA_RATE, SerialPort.DATABITS_8, SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);

		// Leitura e escrita.
		input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));
		output = serialPort.getOutputStream();

		// Adiciona o listener para receber dados.
		serialPort.addEventListener(this);
		serialPort.notifyOnDataAvailable(true);
	}

	// Metodo que recebe os valores enviados pelo arduino.
	@Override
	public void serialEvent(SerialPortEvent oEvent) {
		if (oEvent.getEventType() == SerialPortEvent.DATA_AVAILABLE) {
			try {
				System.out.println(input.readLine());
			} catch (Exception e) {
				System.err.println(e.toString());
			}
		}
	}

	public void sendMessage(String message) throws IOException {
		this.output.write(message.getBytes());
	}
	
}
