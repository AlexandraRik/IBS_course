package ru.appline;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;
import ru.appline.logic.Model;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(urlPatterns = "/delete")

public class ServletDelete extends HttpServlet {
    Model model = Model.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();

   /* protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html;charset=utf-8");
        PrintWriter pw = response.getWriter();
        int id = Integer.parseInt(request.getParameter("id"));
        model.delete(id);
        pw.print("<html>" +
                "<h3>Пользователь " + id + " удален </h3>" +
                "<a href=\"index.jsp\">Домой</a>" +
                "</html>");
    }*/

    protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws IOException {
        StringBuffer j1b = new StringBuffer();
        String line;
        try {
            BufferedReader reader = request.getReader();
            while((line = reader.readLine())!= null)
            {
                j1b.append(line);
            }

        } catch(Exception e){
            System.out.println("Error");

        }
        JsonObject jobj1 = gson.fromJson(String.valueOf(j1b), JsonObject.class);

        int id= jobj1.get("id").getAsInt();
        model.delete(id);

        response.setContentType("application/json;charset=utf-8");
        PrintWriter pw = response.getWriter();
        pw.print(gson.toJson(model.getFromList()));
    }


    }
