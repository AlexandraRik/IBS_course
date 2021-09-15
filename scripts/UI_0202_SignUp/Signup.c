Signup()
{
lr_start_transaction("0202_SignUp");


lr_start_transaction("WebTourConnection"); 

web_reg_find("Text/IC=Web Tours",
		LAST);

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		

	web_set_sockets_option("SSL_VERSION", "2&3");
	
	lr_end_transaction("WebTourConnection", LR_AUTO);

	lr_think_time(10);
	

	lr_start_transaction("PressSignup");

	web_reg_find("Text/IC=User Information",
		LAST);

	web_url("sign up now", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("PressSignup",LR_AUTO);

	lr_think_time(10); 
	
	
	lr_start_transaction("Signup");
	
	//web_reg_find("Text/IC=User Information", LAST);

	//web_reg_find("Text/IC={Username_rnd}", LAST);
	//web_reg_find("Text/IC={Password_rnd}", LAST);
	//web_reg_find("Text/IC=firstName&{FirstName}", LAST);
	//web_reg_find("Text/IC={LastName}", LAST);
	//web_reg_find("Text/IC={Address1}", LAST);
	//web_reg_find("Text/IC={Address2}", LAST);

	

	web_reg_find("Text/IC=Thank you, <b>{Username_rnd}</b>, for registering and welcome to the Web Tours family.",
		LAST);

	web_reg_find("Text/IC=for registering and welcome to the Web Tours family", LAST);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={Username_rnd}", ENDITEM, 
		"Name=password", "Value={Password_rnd}", ENDITEM, 
		"Name=passwordConfirm", "Value={Password_rnd}", ENDITEM, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={Address1}", ENDITEM, 
		"Name=address2", "Value={Address2}", ENDITEM, 
		"Name=register.x", "Value=18", ENDITEM, 
		"Name=register.y", "Value=5", ENDITEM, 
		LAST);

	

	

	lr_think_time(10);
	lr_end_transaction("Signup", LR_AUTO); 
	
	lr_start_transaction("PressNext");
		web_reg_find("Text/IC=User has returned to the home page. ",
		LAST);

	web_url("button_next.gif", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
    lr_end_transaction("PressNext", LR_AUTO);
    
    	
	lr_think_time(10);
	
		lr_start_transaction("SignOff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);
	
	
	lr_end_transaction("0202_SignUp", LR_AUTO);

	return 0;
}