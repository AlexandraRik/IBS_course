package ru.appline;


import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;
import ru.appline.logic.Model;
import ru.appline.logic.User;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(urlPatterns = "/upgrade")
public class ServletUpgrade extends HttpServlet {
    Model model = Model.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();
    protected void doPut(HttpServletRequest request, HttpServletResponse response) throws IOException {
        StringBuffer j2b = new StringBuffer();
        String line;
        try {
            BufferedReader reader = request.getReader();
            while((line = reader.readLine())!= null)
            {
                j2b.append(line);
            }

        } catch(Exception e){
            System.out.println("Error");

        }
        JsonObject jobj2 = gson.fromJson(String.valueOf(j2b), JsonObject.class);
        request.setCharacterEncoding("UTF-8");
        //response.setCharacterEncoding("UTF-8");
        int id = jobj2.get("id").getAsInt();
        String name = jobj2.get("name").getAsString();
        String surname = jobj2.get("surname").getAsString();
        double salary = jobj2.get("salary").getAsDouble();

        User user = new User(name, surname, salary);
        model.put(user, id);
        response.setContentType("application/json;charset=utf-8");
        PrintWriter pw = response.getWriter();
        pw.print(gson.toJson(model.getFromList()));



    }



}
