package sql;

import java.sql.*;

public class RestaurantDB {

    public static final String DB_URL = "jdbc:h2:/home/den/Documents/GitHub/Programming-Labs/Java-2/lab_5/db/restaurant";
    public static final String DB_Driver = "org.h2.Driver";

    public static void main(String[] args) {
        try {
            Class.forName(DB_Driver);
            Connection connection = DriverManager.getConnection(DB_URL);
            System.out.println("Connection success");
            connection.close();
            System.out.println("Disconnection success");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            System.out.println("JDBC driver not found");
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("SQL error");
        }
    }
}
