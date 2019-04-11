<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2019/4/11
  Time: 15:00
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>删除用户</title>
</head>

<body>
<form  method="post" action="DeleteUser">
    <div align="center"><font face="宋体" size="6"><strong>
        删除用户</strong></font><br/>
        <hr/>
        <p>
        </p>
        <p>输入删除的用户名 <input name="username" type="text"/><br/><br/>
            <input type="submit" name="delete" value="删除用户" />
            <br />
            <br />
        </p>
    </div>
</form>
</body>
</html>