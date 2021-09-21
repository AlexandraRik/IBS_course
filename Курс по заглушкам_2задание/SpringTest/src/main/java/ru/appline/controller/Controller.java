package ru.appline.controller;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;
import org.springframework.web.bind.annotation.*;
import ru.appline.logic.Pet;
import ru.appline.logic.PetModel;

import java.io.BufferedReader;
import java.util.Map;

import java.util.concurrent.atomic.AtomicInteger;

@RestController

public class Controller {
    private static final PetModel petModel = PetModel.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();
    private static final AtomicInteger newId = new AtomicInteger(1);

    //@RequestMapping("message")
    //public class messageController {
       /* public List<Map<String, String>> messages = new ArrayList<Map<String, String>>() {
            {
                add(new HashMap<String, String>() {{
                    put("Поздравляем!", "Питомец был создан");
                    put("Запрос", " выполнен");
                }});
            }

            ;

            @GetMapping
            public List<Map<String, String>> list() {
                return messages;
            }*/

    @PostMapping(value = "/createPet", consumes = "application/json", produces = "application/json")

    public String createPet(@RequestBody Pet pet) {
        petModel.add(pet, newId.getAndIncrement());

        String resp = "Вы успешно создали питомца, поздравляем!";
        // JsonObject jobj4 = gson.fromJson(String.valueOf(resp), JsonObject.class);
        return resp;


    }


    @GetMapping(value = "/getAll", produces = "application/json")

    public Map<Integer, Pet> getAll() {
        return petModel.getAll();
    }

    @GetMapping(value = "/getPet", consumes = "application/json", produces = "application/json")
    public Pet getPet(@RequestBody Map<String, Integer> id) {
        return petModel.getFromList(id.get("id"));
    }

    @DeleteMapping(value = "/deletePet", consumes = "application/json", produces = "application/json")
    public void delete(@RequestBody Integer id) {
       petModel.delete(id);

    }

    @PutMapping(value = "/update", consumes = "application/json", produces = "application/json")
    public void update(@RequestBody Pet pet, Integer id) {


        petModel.put(pet, id);

    }
}


