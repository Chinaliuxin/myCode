package toolBean.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBUtil {
    private static Connection conn = null;

    public static Connection getConnection() {
        String driverClass = "com.mysql.jdbc.Driver";
        String url =//与创建数据库的代码结合，保证访问数据库时不出现乱码
                "jdbc:mysql://localhost:3306/db";
        String username = "root";
        String password = "root";
        try {
            Class.forName(driverClass);// 加载数据库驱动
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        if (conn == null)
            try {
                conn = DriverManager.getConnection(url, username, password);//建立连接
            } catch (SQLException e) {
                e.printStackTrace();
                System.out.print("数据库连接失败！");
            }
        return conn;
    }
}