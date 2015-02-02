import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.JTextPane;

import net.miginfocom.swing.MigLayout;

public class MainWindow implements SerialPortEventListener {

	private JFrame frame;

	private JTextPane txtResultados;

	// -Djava.library.path=C:\ardulink
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				try {
					MainWindow window = new MainWindow();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MainWindow() {
		this.initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		this.frame = new JFrame();
		this.frame.setBounds(100, 100, 450, 300);
		this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.frame.getContentPane().setLayout(
				new MigLayout("", "[grow][grow]", "[][grow]"));

		final JTextField txtEnviar = new JTextField();
		this.frame.getContentPane().add(txtEnviar, "cell 1 0,growx");
		txtEnviar.setColumns(50);

		this.txtResultados = new JTextPane();
		this.txtResultados.setText("");
		JScrollPane scroll = new JScrollPane(this.txtResultados);
		this.frame.getContentPane().add(scroll, "cell 0 1 2 1,grow");

		try {
			this.abrirPortaSerial();
		} catch (Exception ex) {
			JOptionPane.showMessageDialog(this.frame,
					"Erro ao abrir a comunicacao Serial.\n" + ex.getMessage());
		}

		JButton btnEnviar = new JButton("Enviar");
		btnEnviar.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				MainWindow.this.enviarMensagem(txtEnviar.getText());
				txtEnviar.setText("");
			}
		});
		this.frame.getContentPane().add(btnEnviar, "cell 0 0");
	}


	// Buffer de leitura.
	private BufferedReader input;

	// Metodo que recebe os valores enviados pelo arduino.
	@Override
	public void serialEvent(SerialPortEvent oEvent) {
		if (oEvent.getEventType() == SerialPortEvent.DATA_AVAILABLE) {
			try {
				this.txtResultados.setText(this.input.readLine() + "\n"
						+ this.txtResultados.getText());
			} catch (Exception e) {
				System.err.println(e.toString());
			}
		}
	}

	// Buffer de escrita.
	private OutputStream output;

	public void enviarMensagem(String mensagem) {
		try {
			this.output.write(mensagem.getBytes());
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}

	// Timeout esperado para a abertura da comunicacao.
	private static final int TIMEOUT = 2000;

	// Frequencia de comunicacao da porta serial.
	private static final int DATA_RATE = 9600;

	// Porta que sera aberta (pode variar de acordo
	// com a USB que foi conectador o Arduino).
	private static final String COM = "COM9";

	// Porta serial.
	private SerialPort serialPort;

	public void abrirPortaSerial() throws Exception {
		// Criada a porta serial.
		CommPortIdentifier portId = CommPortIdentifier.getPortIdentifier(COM);

		// Abrindo a comunicacao com a porta serial.
		this.serialPort = (SerialPort) portId.open("porta-serial", TIMEOUT);

		// Parametros de comunicacao com a porta serial.
		this.serialPort.setSerialPortParams(DATA_RATE, SerialPort.DATABITS_8,
				SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);

		// Leitura e escrita.
		this.input = new BufferedReader(new InputStreamReader(
				this.serialPort.getInputStream()));
		this.output = this.serialPort.getOutputStream();

		// Adiciona o listener para receber dados.
		this.serialPort.addEventListener(this);
		this.serialPort.notifyOnDataAvailable(true);
	}

}
