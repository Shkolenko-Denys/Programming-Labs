import javax.swing.*;
import javax.swing.text.*;


/**
 * Ввод текста в графическое окно приложения.
 * В окне определена строка меню (JMenuBar), в которой определены два меню
 * (JMenu) – "Шрифт" и "Стиль". В меню "Шрифт" определены три пункта меню
 * (JRadioButtonMenuItem): "Times New Roman" (шрифт по умолчанию),
 * "Arial" и "Verdana". В меню "Стиль" определены четыре пункта меню
 * (JRadioButtonMenuItem): "Простой" (шрифт по умолчанию), "Жирный",
 * "Курсив" и "Жирный курсив". В текстовой панели (JTextPane) "Ввод текста"
 * окна приложения вводится текст, набираемый на клавиатуре.
 * При выборе одного из пунктов меню текст в панели выводится
 * соответствующим шрифтом и/или стилем.
 * */
public class Task1 extends JFrame {

    private String font = "Times New Roman";
    private Boolean is_bold = false;
    private Boolean is_italic = false;

    private void updateStyle(JTextPane editor) {
        Style textStyle = editor.addStyle("current", null);
        StyleConstants.setFontFamily(textStyle, font);
        int size = 30;
        StyleConstants.setFontSize(textStyle, size);
        StyleConstants.setBold(textStyle, is_bold);
        StyleConstants.setItalic(textStyle, is_italic);
        editor.setLogicalStyle(textStyle);
    }

    public Task1() {
        super("Task 1");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        JMenuBar menuBar = new JMenuBar();

        JMenu menuFont = new JMenu("Шрифт");
        JRadioButtonMenuItem timesNewRoman = new JRadioButtonMenuItem(
                "Times New Roman", true);
        JRadioButtonMenuItem arial = new JRadioButtonMenuItem(
                "Arial");
        JRadioButtonMenuItem verdana = new JRadioButtonMenuItem(
                "Verdana");

        menuFont.add(timesNewRoman);
        menuFont.add(arial);
        menuFont.add(verdana);

        ButtonGroup groupFonts = new ButtonGroup();
        groupFonts.add(timesNewRoman);
        groupFonts.add(arial);
        groupFonts.add(verdana);

        JMenu menuStyle = new JMenu("Стиль");
        JRadioButtonMenuItem plain = new JRadioButtonMenuItem(
                "Простой", true);
        JRadioButtonMenuItem bold = new JRadioButtonMenuItem(
                "Жирный");
        JRadioButtonMenuItem italic = new JRadioButtonMenuItem(
                "Курсив");
        JRadioButtonMenuItem boldItalic = new JRadioButtonMenuItem(
                "Жирный курсив");

        menuStyle.add(plain);
        menuStyle.add(bold);
        menuStyle.add(italic);
        menuStyle.add(boldItalic);

        ButtonGroup groupStyles = new ButtonGroup();
        groupStyles.add(plain);
        groupStyles.add(bold);
        groupStyles.add(italic);
        groupStyles.add(boldItalic);

        menuBar.add(menuFont);
        menuBar.add(menuStyle);
        menuBar.add(Box.createHorizontalGlue());
        setJMenuBar(menuBar);

        JTextPane textEditor = new JTextPane();
        updateStyle(textEditor);

        timesNewRoman.addActionListener(e -> {
            font = "Times New Roman";
            updateStyle(textEditor);
        });
        arial.addActionListener(e -> {
            font = "Arial";
            updateStyle(textEditor);
        });
        verdana.addActionListener(e -> {
            font = "Verdana";
            updateStyle(textEditor);
        });

        plain.addActionListener(e -> {
            is_bold = false;
            is_italic = false;
            updateStyle(textEditor);
        });
        bold.addActionListener(e -> {
            is_bold = true;
            is_italic = false;
            updateStyle(textEditor);
        });
        italic.addActionListener(e -> {
            is_italic = true;
            is_bold = false;
            updateStyle(textEditor);
        });
        boldItalic.addActionListener(e -> {
            is_italic = true;
            is_bold = true;
            updateStyle(textEditor);
        });

        getContentPane().add(new JScrollPane(textEditor));
        setSize(500, 500);
        setLocation(500, 250);
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Task1::new);
    }
}
