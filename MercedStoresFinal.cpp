#include <iostream>
#include <sqlite3.h>
#include <string>
#include<stdio.h>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName) 
{ 
    int i; 
    fprintf(stderr, "%s", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 

}

int Business(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("MercedStore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("SELECT * FROM Business"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0);
}
int Vacancies(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("SELECT * FROM Vacancies"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0);
}

static int removeBusiness(){

sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 

    Business();

    std::string busid;
    int update_option = 0;
    std::cout << "Which Business would you like to remove? (busid) \n";
    std::cin >> busid;
    
    std::string sqlquery = "DELETE FROM Business WHERE b_busid = "+busid+" \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 


}

static int removeVacancies(){

sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 

    Vacancies();

    std::string vacid;
    int update_option = 0;
    std::cout << "Which Vacant Business would you like to remove? (vacid) \n";
    std::cin >> vacid;
    
    std::string sqlquery = "DELETE FROM Vacancies WHERE v_vacid = "+vacid+" \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 


}

static int insertBusiness(){
    sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 

    Business();

    std::string busid;
    int update_option = 0;

    std::string b_busid, b_ownerid, b_address, b_telephone, b_rating, b_openinghours, b_closinghours, b_districtid, b_shopid;
    std::cout << "What would you like to insert? \n";
    std::cout << "busid?, " << "ownerid?, " << "address?, " << "telephone?, " << "b_rating?, " << "openinghours?, " << "closinghours?, " << "districtid?, " << "shopid?" "\n";
    std::cin >> b_busid >> b_ownerid >> b_address >> b_telephone >> b_rating >> b_openinghours >> b_closinghours >> b_districtid >> b_shopid;
    
    std::string sqlquery = "INSERT INTO Business Values ('"+b_busid+"', '"+b_ownerid+"', '"+b_address+"', '"+b_telephone+"', '"+b_rating+"', '"+b_openinghours+"', '"+b_closinghours+"', '"+b_districtid+"', '"+b_shopid+"') \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}

static int insertVacancies(){

sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 

    Vacancies();

    std::string vacid;
    int update_option = 0;

    std::string v_vacid, v_address, v_owner, v_telephone, v_rent, v_districtid;
    std::cout << "What would you like to insert? \n";
    std::cout << "vacid?, " << "address?, " << "owner?, " << "telephone?, " << "rent?, " << "districtid?" "\n";
    std::cin >> v_vacid >> v_address >> v_owner >> v_telephone >> v_rent >> v_districtid;

    std::string sqlquery = "INSERT INTO Vacancies Values ('"+v_vacid+"', '"+v_address+"', '"+v_owner+"', '"+v_telephone+"', '"+v_rent+"', '"+v_districtid+"') \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 


}

static int modifyBusiness(){
    sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 

    Business();

    std::string busid;
    int update_option = 0;
    std::cout << "Which Business would you like to update? (busid) \n";
    std::cin >> busid;
    std:: cout << "What information do you want to update? \n";
    std:: cout << "Press 1 for Business Owner ID \n";
    std:: cout << "Press 2 for Business Address \n";
    std:: cout << "Press 3 for Business telephone \n";
    std:: cout << "Press 4 for Business Rating \n";
    std:: cout << "Press 5 for Business Opening Hours \n";
    std:: cout << "Press 6 for Business Closing Hours \n";
    std:: cout << "Press 7 for Business District ID \n";
    std:: cout << "Press 8 for Business Shop ID \n";
    std::cin >> update_option;

    std::string option;
    if (update_option == 1){
    	option = "b_ownerid";
    }
    else if (update_option == 2){
    	option = "b_address";
    }
    else if (update_option == 3){
    	option = "b_telephone";
    }
    else if (update_option == 4){
    	option = "b_rating";
    }
    else if (update_option == 5){
    	option = "b_openinghours";
    }
    else if (update_option == 6){
    	option = "b_closinghours";
    }
    else if (update_option == 7){
    	option = "b_districtid";
    }
    else if (update_option == 8){
    	option = "b_shopid";
    }
    std::cout << "What would you like to change it to? \n";
    string modify;
    std::cin >> modify;
    //getline(cin,modify);
    
    std::string sqlquery = "Update business SET "+option+" = '"+modify+"' WHERE b_busid = " +busid + "\n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int modifyVacancies(){
    sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 

    Vacancies();

    std::string vacid;
    int update_option = 0;
    std::cout << "Which Vacant Location would you like to update? (vacid) \n";
    std::cin >> vacid;
    std:: cout << "What information do you want to update?";
    std:: cout << "Press 1 for Vacant Locations Address \n";
    std:: cout << "Press 2 for Vacant Locations Owner ID \n";
    std:: cout << "Press 3 for Vacant Locations telephone \n";
    std:: cout << "Press 4 for Vacant Locations Rent \n";
    std:: cout << "Press 5 for Vacant Locations District ID \n";

    std::cin >> update_option;

    std::string option;
    if (update_option == 1){
    	option = "v_address";
    }
    else if (update_option == 2){
    	option = "v_ownerid";
    }
    else if (update_option == 3){
    	option = "v_telephone";
    }
    else if (update_option == 4){
    	option = "v_rent";
    }
    else if (update_option == 5){
    	option = "b_districtid";
    }
    std::string modify;
    std::cout << "What would you like to change it to? \n";
    std::cin >> modify;
    //std::getline(std::cin,modify);
    
    std::string sqlquery = "Update vacancies SET "+option+" = '"+modify+"' WHERE v_vacid = " +vacid + "\n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
int modify(){
	std::cout << "Press 1 If interested in modifying Businesses \n";
	std::cout << "Press 2 If interested in modifying Vacancies \n";
	int interest = 0;
	std::cin >> interest;
	if(interest == 1){
		modifyBusiness();
	}
	else if(interest = 2){
		modifyVacancies();
	}
	return 0;
}
int remove(){
	std::cout << "Press 3 If interested in removing from Businesses \n";
	std::cout << "Press 4 If interested in removing from Vacancies \n";
	int interest = 0;
	std::cin >> interest;
	if(interest == 3){
		removeBusiness();
	}
	else if(interest = 4){
		removeVacancies();
	}
	return 0;
}

static int insert(){

    std::cout << "Press 5 If interested in adding Businesses \n";
	std::cout << "Press 6 If interested in adding Vacancies \n";
	int interest = 0;
	std::cin >> interest;
	if(interest == 5){
		insertBusiness();
	}
	else if(interest = 6){
		insertVacancies();
	}
	return 0;
}
int admin(){
	std::string username = "admin";
	std::string password = "pass";
	std::string userinput;
	std::string passinput;
	bool valid_user = false;
	bool valid_pass = false;
	int valid_user_counter = 0;
	int valid_pass_counter = 0;

	while( (valid_user == false) && (valid_pass == false)){
		std::cout << "Username: ";
		std::cin >> userinput;
		std::cout << "Password: ";
		std::cin >> passinput;

		valid_user = false;
		valid_pass = false;

		if(username == userinput){
			if(password == passinput){
				std::cout << "You're In! \n";
				valid_pass = true;
				valid_user = true;
			}
			else{
				std::cout << "Incorrect Password! \n";
				valid_pass = false;
				valid_user = false;
			}
		}
		else
			std::cout << "Incorrect Username! \n";
			valid_user = false;
	}
 
 	std::cout << "Press 1 if interested in Modifiyng a Business or Vacancy. \n";
	std::cout << "Press 2 if interested in Removing a Business or Vacancy. \n";
	std::cout << "Press 3 if interested in Adding a Business or Vacancy. \n";
	int interest = 0;
	cin >> interest;
	if(interest == 1){
		modify();
	}
   	else if(interest == 2){
   		remove();
   	}
	else if (interest == 3){
		insert();
	}
	

	return 0;
}



static int BusinessList(){ 
    sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("SELECT o_name AS Owner, b_address AS Address, b_telephone AS Telephone, b_rating AS Rating, b_openinghours AS Open, b_closinghours AS Close, d_districtname AS District, s_departments AS Department FROM Owner, District, ShopType, Business WHERE o_ownerid = b_ownerid AND d_districtid = b_districtid AND s_shopid = b_shopid"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
} 
static int VacancyList(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("SELECT v_address AS Address, o_name AS Owner, v_telephone AS Telephone, v_rent AS RENTorLEASE, d_districtname AS District FROM Vacancies, Owner, District WHERE o_ownerid = v_ownerid AND d_districtid = v_districtid"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int LocalBusinessList(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("SELECT b_address, b_telephone, b_rating, d_districtname From Business, District, ShopType WHERE b_districtid = d_districtid AND b_shopid = s_shopid AND s_type = 'local'"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int CorporateBusinessList(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("SELECT b_address, b_telephone, b_rating, d_districtname From Business, District, ShopType WHERE b_districtid = d_districtid AND b_shopid = s_shopid AND s_type = 'corporate'"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int VacanciesForRent(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("SELECT v_address, o_name, v_telephone, d_districtname FROM Vacancies, Owner, District WHERE d_districtid = v_districtid AND o_ownerid = v_ownerid AND v_rent = 'yes'"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int VacanciesForSale(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("SELECT v_address, o_name, v_telephone, d_districtname FROM Vacancies, Owner, District WHERE d_districtid = v_districtid AND o_ownerid = v_ownerid AND v_rent = 'no'"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int CorpBussPerDist(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("Select d_districtname AS DistrictName, count(s_type) AS Total from ShopType, Business, District where b_districtid = d_districtid and b_shopid = s_shopid and s_type = 'corporate' group by d_districtname"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int LocalBussPerDist(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("Select d_districtname AS DistrictName, count(s_type) AS Total from ShopType, Business, District where b_districtid = d_districtid and b_shopid = s_shopid and s_type = 'local' group by d_districtname"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int OwnerInfoVRent(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("Select v_address, o_name, o_telephone, o_email from Owner, Vacancies , District where o_ownerid = v_ownerid and v_districtid = d_districtid and v_rent = 'yes'"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int OwnerInfoVSale(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("Select v_address, o_name, o_telephone, o_email from Owner, Vacancies , District where o_ownerid = v_ownerid and v_districtid = d_districtid and v_rent = 'no'"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int LowRatePerDist(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("Select d_districtname, s_departments, b_address, min(b_rating) from Business, Owner, District, ShopType where b_ownerid = o_ownerid and b_districtid = d_districtid and b_shopid = s_shopid group by d_districtname"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}
static int HighRatePerDist(){
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("Mercedstore.db", &DB); 
    std::string data("\n"); 
  
    std::string sql("Select d_districtname, s_departments, b_address, max(b_rating) from Business, Owner, District, ShopType where b_ownerid = o_ownerid and b_districtid = d_districtid and b_shopid = s_shopid group by d_districtname"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
}

static int user(){
	std::cout << "Below Are the List of Functions that you may search in our database" << std::endl;
	std::cout << "Press 1 to search the whole business list \n";
	std::cout << "Press 2 to search the whole vacancy list \n";
	std::cout << "Press 3 to search the list of local businesses \n";
	std::cout << "Press 4 to search the list of corporate businesses \n";
	std::cout << "Press 5 to search the list of vacancies for rent \n";
	std::cout << "Press 6 to search the list of vacancies for sale \n";
	std::cout << "Press 7 to search the number of Corporate Businesses per District \n";
	std::cout << "Press 8 to search the number of Local Businesses per District \n";
	std::cout << "Press 9 to search the owner contact information of vacancies for rent \n";
	std::cout << "Press 10 to search the owner contact information of vacancies for sale \n";
	std::cout << "Press 11 to search the lowest rating business per district \n";
	std::cout << "Press 12 to search the highest rating business per district \n";


	int x = 0;
	std::cin >> x;

	if (x == 1){
		BusinessList();
	}
	else if (x == 2){
		VacancyList();
	}
	else if (x == 3){
		LocalBusinessList();
	}
	else if (x == 4){
		CorporateBusinessList();
	}
	else if (x == 5){
		VacanciesForRent();
	}
	else if (x == 6){
		VacanciesForSale();
	}
	else if (x == 7){
		CorpBussPerDist();
	}
	else if (x == 8){
		LocalBussPerDist();
	}
	else if (x == 9){
		OwnerInfoVRent();
	}
	else if (x == 10){
		OwnerInfoVSale();
	}
	else if (x == 11){
		LowRatePerDist();
	}
	else if (x == 12){
		HighRatePerDist();
	}

	return 0;
}




int main(int argc, char** argv)
{

	int UserAdmin;
	bool valid_input = false;

	do{
	std::cout << "If you are a User, press 0. If you are an Administrator, press 1." << std::endl;
	std::cin>> UserAdmin;
	if (UserAdmin == 0){
		user();
		valid_input = true;
	}
	else if (UserAdmin == 1){
		admin();
		valid_input = true;
	}
	else
	std::cout << "Invalid Input" << std::endl;
	}while (valid_input == false);

	return(0);
}