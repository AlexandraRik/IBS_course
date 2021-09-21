<%@ page import="ru.appline.logic.Model"%><%--
  Created by IntelliJ IDEA.
  User: Александра
  Date: 14.09.2021
  Time: 21:04
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>Title</title>
  </head>
  <body>
  <h1>Домашняя страница по работе с пользователями</h1>
  Введите ID пользователя (0 - для вывода всего списка пользователя)
  <br/>
  Доступно: <%
  Model model = Model.getInstance();
  out.print(model.getFromList().size());
  %>
  <form method="get" action="get">
    <label>ID:
      <input type="text" name="id"><br/>
    </label>
    <button type="submit">Поиск</button>
  </form>
  <a href="addUser.html">Создать нового пользователя</a>
  <a href="deleteUser.html">Удалить пользователя</a>
  <a href="upgradeUser.html">Обновить информацию о пользователе</a>
  <a href="Calculator.html">Калькулятор</a>
  </body>
</html>
