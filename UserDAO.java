package toolBean.db;

import valueBean.User;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class UserDAO {
    private static Connection conn=null;
    private Statement stmt=null;
    //构造函数中完成对数据库进行初始化
    public UserDAO() {
        //创建连接
        conn=DBUtil.getConnection();
        try {
            //创建Statement
            stmt=conn.createStatement();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    //将对象user添加到表中
    public void Add(User user) throws SQLException
    {
        String sql="INSERT INTO user(username,password) VALUES('"
                +user.getUsername()+"','"+user.getPassword()+"')";
        stmt.executeUpdate(sql);
        //此处可以使用预定义语句PreparedStatement
    }


    //根据用户名（关键字）从数据库删除相应的记录
    public void Delete(String username) throws SQLException
    {
        String sql="Delete From user Where username='"+username+"'";
        stmt.executeUpdate(sql);
    }

    //修改数据库中的user
    public void Update(User user) throws SQLException
    {
        String sql="UPDATE user set password='"
                +user.getPassword()+"' where username='"+user.getUsername()+"'";
        stmt.executeUpdate(sql);
    }

    //根据用户名称（关键字）从数据库中查找记录，并将找到的记录写入对象user中返回
    public User searchByUsername(String username) throws SQLException
    {
        User user=new User();
        String sql="select * from user where username='"+username+"'";
        ResultSet rs=stmt.executeQuery(sql);
        while(rs.next())
        {
            String name=rs.getString("username");
            if(name.equals(username))
            {
                //将从数据库查找得到的记录存入对象user中
                user.setUsername(name);
                user.setPassword(rs.getString("password"));
                if(rs!=null)
                    rs.close();
                return user;
            }
        }
        return null;//查找不到返回null
    }
    //根据用户判断该记录是否存在
    public boolean exists(String username)
    {
        boolean rtn=false;
        try {
            if(searchByUsername(username)!=null)
                rtn=true;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return rtn;
    }
    //关闭与访问数据库有关连接
    public void finalize()
    {
        try {
            if(stmt!=null)
                stmt.close();
            if(conn!=null)
                conn.close();
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
