Action()
{
	
	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	web_reg_find("Text=Advantage Shopping", 
		LAST);

lr_start_transaction("AOS-S03-01 Access AOS URL");

	web_url("www.advantageonlineshopping.com", 
		"URL={AOS_URL}/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/main.min.js", ENDITEM, 
		"Url=/services.properties", ENDITEM, 
		"Url=/css/images/logo.png", ENDITEM, 
		"Url=/css/images/closeDark.png", ENDITEM, 
		"Url=/css/fonts/roboto_medium_macroman/Roboto-Medium-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/fonts/roboto_light_macroman/Roboto-Light-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/fonts/roboto_regular_macroman/Roboto-Regular-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/images/arrow_right.png", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=speakers", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=laptops", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=tablets", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=mice", ENDITEM, 
		"Url=/css/fonts/roboto_bold_macroman/Roboto-Bold-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=headphones", ENDITEM, 
		"Url=/css/fonts/roboto_thin_macroman/Roboto-Thin-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/images/Special-offer.jpg", ENDITEM, 
		"Url=/css/images/GoUp.png", ENDITEM, 
		"Url=/css/images/twitter.png", ENDITEM, 
		"Url=/css/images/facebook.png", ENDITEM, 
		"Url=/css/images/linkedin.png", ENDITEM, 
		"Url=/css/images/Banner1.jpg", ENDITEM, 
		"Url=/css/images/Banner2.jpg", ENDITEM, 
		"Url=/css/images/Banner3.jpg", ENDITEM, 
		"Url=/css/images/Popular-item2.jpg", ENDITEM, 
		"Url=/css/images/Popular-item3.jpg", ENDITEM, 
		"Url=/css/images/Popular-item1.jpg", ENDITEM, 
		"Url=/css/images/FacebookLogo.png", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		LAST);

	web_url("ALL", 
		"URL={AOS_URL}/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("GetAccountConfigurationRequest", 
		"URL={AOS_URL}/accountservice/ws/GetAccountConfigurationRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={AOS_URL}/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_url("categories", 
		"URL={AOS_URL}/catalog/api/v1/categories", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("search", 
		"URL={AOS_URL}/catalog/api/v1/deals/search?dealOfTheDay=true", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_url("popularProducts.json", 
		"URL={AOS_URL}/app/tempFiles/popularProducts.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("home-page.html", 
		"URL={AOS_URL}/app/views/home-page.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={AOS_URL}/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("AOS-S03-01 Access AOS URL",LR_AUTO);

	lr_think_time(10);
	

/*Correlation comment: Automatic rules - Do not change!  
Original value='939048723' 
Name ='loginUser' 
Type ='Manual'*/
	web_reg_save_param_xpath(
		"ParamName=userId",
		"QueryString=//ns2:userId/text()",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);
		
		web_reg_save_param_xpath(
		"ParamName=t_authorization",
		"QueryString=//ns2:t_authorization/text()",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);
	
lr_start_transaction("AOS-S03-02 Sign In");

	web_custom_request("AccountLoginRequest", 
		"URL={AOS_URL}/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={AOS_URL}/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{loginPassword}</loginPassword><loginUser>{loginUser}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);
	
	web_add_header("Authorization",
		"Basic {t_authorization}");

	web_url("loginUser",
		"URL={AOS_URL}/order/api/v1/carts/{userId}",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={AOS_URL}/",
		"Snapshot=t20.inf",
		"Mode=HTML",
		LAST);

lr_end_transaction("AOS-S03-02 Sign In",LR_AUTO);

	lr_think_time(10);
	
	
	web_reg_find("Text=Logout Successful", 
		LAST);

lr_start_transaction("AOS-S03-03 Sign Out");

	web_custom_request("AccountLogoutRequest",
		"URL={AOS_URL}/accountservice/ws/AccountLogoutRequest",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer={AOS_URL}/",
		"Snapshot=t21.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=UTF-8",
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>Basic {t_authorization}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>",
		LAST);

lr_end_transaction("AOS-S03-03 Sign Out",LR_AUTO);

	lr_think_time(10);

	return 0;
}