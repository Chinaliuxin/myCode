<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2019/4/11
  Time: 15:06
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html; charset=utf-8" language="java" import="java.sql.*" errorPage="" %>
<%@page import="toolBean.db.UserDAO"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<%
    String username=request.getParameter("queryName");
    valueBean.User user=new valueBean.User();
    if(username!=null&&username!="")
    {
        UserDAO dbUser = new UserDAO();
        valueBean.User temp=dbUser.searchByUsername(username);
        if(temp==null)
        {
            out.print("用户名不存在！");
        }
        else
            user=temp;//防止user为null，导致下文的user.getUsername()产生异常
    }
%>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>查询和修改用户</title>
</head>

<body>
<div align="center">
    <form name="query" method="post" action="">
        <font face="宋体" size="6"><strong>查询和修改用户</strong></font><br/><hr/><br/>
        输入查询的用户名：  <input name="queryName" type="text"/> <input type="submit" name="query" value="查询用户" /><br/><br/><hr/><br/>
    </form>

    <form name="modify" method="post" action="ModifyUser">
        用户名：
        <input name="modfyName" type="text" value="<%=user.getUsername()%>" readonly="readonly" />
        <br/><br/>
        密&nbsp;&nbsp;码：
        <input name="password" type="text" value="<%=user.getPassword()%>"/>
        <br /><br />
        <input type="submit" name="modify" value="修改用户" />
    </form>
    <hr/>
    <a href="DeleteUser.jsp">删除用户</a><br/>
    <a href="AddUser.jsp">添加用户</a><br/>
</div>
</body>
</html>