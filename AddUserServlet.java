package servlet.user;

import toolBean.db.UserDAO;
import valueBean.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

@WebServlet("/AddUser")
public class AddUserServlet extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        //返回上页
        String goBack="<br><a href='javascript:window.history.go(-1);'>返回上页</a>";
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out = response.getWriter();

        String username=request.getParameter("username");
        if(username==null||username.equals(""))
        {
            out.print("用户名不能为空！");
            out.print(goBack);
        }
        String password=request.getParameter("password");
        User user=new User();
        user.setUsername(username);
        user.setPassword(password);   //注入属性

        UserDAO userDB=new UserDAO();
        if(userDB.exists(user.getUsername()))
        {
            out.print("用户名已存在！");
            out.print(goBack);
            return;
        }
        try {
            userDB.Add(user);
        } catch (SQLException e) {
            e.printStackTrace();
            out.print("添加失败:"+e.getLocalizedMessage());
            out.print(goBack);
            return;
        }
        out.print("添加成功！");
        out.print(goBack);
        out.close();
    }
}