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

@WebServlet(urlPatterns = "/calc")
public class ServletCalc extends HttpServlet {
    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        StringBuffer j3b = new StringBuffer();
        String line;
        try {
            BufferedReader reader = request.getReader();
            while((line = reader.readLine())!= null)
            {
                j3b.append(line);
            }

        } catch(Exception e){
            System.out.println("Error");

        }

        JsonObject jobj3 = gson.fromJson(String.valueOf(j3b), JsonObject.class);
        int a = jobj3.get("a").getAsInt();
        int b = jobj3.get("b").getAsInt();
        String opr = jobj3.get("opr").getAsString();
        int result = a+b;


        response.setContentType("application/json;charset=utf-8");
        if(opr == "+")
        {
            result= a+b;
            response.setContentType("application/json");
            //PrintWriter out = response.getWriter();
            //String jsonStr = "\"Результаты:\" + result";
            //out.print(jsonStr);
            JsonObject jobj4 = gson.fromJson(String.valueOf(result), JsonObject.class);
            response.setContentType("application/json;charset=utf-8");
            PrintWriter pw = response.getWriter();
            pw.print(gson.toJson(jobj4));

        }



        //PrintWriter pw = response.getWriter();
        //pw.print(gson.toJson(response.));
        /*else
        {
            response.setContentType("application/json;charset=utf-8");
            PrintWriter pw = response.getWriter();
            pw.print("Другие операции еще не реализованы");
        }*/

    }

}
