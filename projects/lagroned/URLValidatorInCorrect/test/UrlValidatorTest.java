
import junit.framework.TestCase;
import java.util.Random;
//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {

   String[] validSchemes = {"http://","https://","ftp://"};
   String[] invalidSchemes = {"4abc"," ", "+-"};
   String[] validAuthority = {"www.google.com","0.0.0.0","OSU.edu"};
   String[] invalidAuthority = {".~google.com","1.2.3",""};
   String[] validPort = {"www.google.com:80","www.google.com:21","www.google.com:443"};
   String[] invalidPort = {"www.google.com:65537","www.google.com:-15","-010"};
   String[] validPath = { "/path", "/123", "/path/", "/path/path","/@"};
   String[] invalidPath = {"//path", "/path//path","/*","{a,b,c}","[]"};
   String[] validQuery = { "?", "?key=value", "#"};

   int numberOfRuns = 25;

   public static String selectRandom(Random random, String[] array){

       String selection = array[random.nextInt(array.length)];
       return selection;

   }
   public UrlValidatorTest(String testName) {
      super(testName);
   }



   public void testManualTest()
   {
//You can use this function to implement your manual testing
	   UrlValidator url = new UrlValidator();
	   UrlValidator url_scheme = new UrlValidator(null,null, UrlValidator.ALLOW_ALL_SCHEMES);

//*******************************************************************************
//   Without an ALLOW_ALL_SCHEME
//*******************************************************************************
	   System.out.println("Without an ALLOW_ALL_SCHEME");
	   String message = "http://www.google.com";
	   if (url.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }
	   System.out.println("\n");
	   System.out.println("Without an ALLOW_ALL_SCHEME");
	   message = "http://";
	   if (url.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Without an ALLOW_ALL_SCHEME");
	   message = "https://";
	   if (url.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Without an ALLOW_ALL_SCHEME");
	   message = "ftp://";
	   if (url.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Without an ALLOW_ALL_SCHEME");
	   message = "google.com";
	   if (url.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Without an ALLOW_ALL_SCHEME");
	   message = "youtube.com";
	   if (url.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Without an ALLOW_ALL_SCHEME");
	   message = "0.0.0.0";
	   if (url.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Without an ALLOW_ALL_SCHEME");
	   message = "255.255.255.255";
	   if (url.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

//*******************************************************************************
//   With an ALLOW_ALL_SCHEME
//*******************************************************************************
	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");

	   message = "http://";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   message = "3ht://";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   message = "3ht://";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   message = "http://google.com";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   message = "http://youtube.com";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   message = "http://0.0.0.0";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   message = "http://aaa.";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   message = "http://1.2.3.4.5";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   message = "http://.aaa";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   message = "http://go.a";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }
//*******************************************************************************
//   With certain schemes passed such as http and  https
//*******************************************************************************
	   System.out.println("\n");
	   System.out.println("With certain schemes passed such as http and https");
	   String [] schemes = {"http", "https"};
	   UrlValidator url_s = new UrlValidator(schemes);

	   message = "http://";
	   if (url_s.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With certain schemes passed such as http and https");
	   message = "https://";
	   if (url_s.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With certain schemes passed such as http and https");
	   message = "ftp://";
	   if (url_s.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With certain schemes passed such as http and https");
	   message = "3ht://";
	   if (url_s.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("With certain schemes passed such as http and https");
	   message = "http://";
	   if (url_s.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

//*******************************************************************************
//   With an ALLOW_ALL_SCHEME
//*******************************************************************************
	   System.out.println("\n");
	   System.out.println("With an ALLOW_ALL_SCHEME");
	   System.out.println("Adding port 80 to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com:80";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding port -1 to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com:-1";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding port 65535 to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com:65535";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding port 0 to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com:0";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding port 65536 to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com:65536";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /test1 to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/test1";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /t123 to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/t123";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /$23 to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/$23";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }


	   System.out.println("\n");
	   System.out.println("Adding path /$# to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/$#";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /$#/file to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/$#/file";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /$#//file to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/$#//file";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /$23/file to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/$23/file";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /../ to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/../";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /.. to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/..";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /test1/file to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/test1/file";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /test1//file to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/test1//file";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /test1/ to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/test1/";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding path /t123/file to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com/t123/file";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding query ?action=view to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com?action=view";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding query ?action=edit&mode=up to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com?action=edit&mode=up";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding query ?name=ferret to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com?name=ferret";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding query ?name=ferret&color=purple to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com?name=ferret&color=purple";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

	   System.out.println("\n");
	   System.out.println("Adding query ?# to the url with ALLOW_ALL_SCHEME");
	   message = "http://google.com?#";
	   if (url_scheme.isValid(message)) {
		    System.out.println(message);
		   	System.out.println("Url is valid");
	   }else {
		   System.out.println(message);
		   System.out.println("Url is not valid");
	   }

   }

   /*Test Valid Schemes*/
   public void testYourFirstPartition()
   {
       Random rand = new Random();
       UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

       for(int i = 0; i < validSchemes.length; i++ ){

           System.out.println("\nTesting Valid Schemes: " + validSchemes[i]);
           String currentScheme = validSchemes[i];
           boolean result = false;

            try{result= urlVal.isValid(currentScheme);}

            catch(Error e)
    	    {System.out.println(currentScheme+" caused "+e);continue;} //print URL causing errors, the error message then skip it
             System.out.println(currentScheme+" returned "+result); //if a result can be calculated, returned it and URL
      }



       for(int i = 0; i < invalidSchemes.length; i++ ){

           System.out.println("\nTesting inValid Schemes: " + invalidSchemes[i]);
           String currentScheme = invalidSchemes[i];
           boolean result = false;

            try{result= urlVal.isValid(currentScheme);}

            catch(Error e)
            {System.out.println(currentScheme+" caused "+e);continue;} //print URL causing errors, the error message then skip it
             System.out.println(currentScheme+" returned "+result); //if a result can be calculated, returned it and URL
      }
   }

   /*Test Valid and Invalid Authority*/
   public void testYourSecondPartition(){

    UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

    Random rand = new Random();

       for(int i = 0; i < numberOfRuns; i++ ){

           String currentAuthority = selectRandom(rand,validAuthority);
           String currentScheme = selectRandom(rand,validSchemes);
           String combinedURL = currentScheme + currentAuthority;

           System.out.println("\nTesting Valid Authority: " + combinedURL);


           boolean result = false;

           try{result= urlVal.isValid(combinedURL);}
            catch(Error e)
            {System.out.println(combinedURL +" caused " +e); continue;} //print URL causing errors, the error message then skip it
             System.out.println(combinedURL +" returned "+ result); //if a result can be calculated, returned it and URL
           }


       for(int i = 0; i < numberOfRuns; i++ ){

           String currentInvAuthority = selectRandom(rand,invalidAuthority);
           String currentInvScheme = selectRandom(rand, validSchemes);
           String combinedInvURL = currentInvScheme + currentInvAuthority;
           boolean result = false;

           System.out.println("\nTesting invalid Authority: " + combinedInvURL);

           try{result= urlVal.isValid(combinedInvURL);}
            catch(Error e)
            {System.out.println(combinedInvURL +" caused " +e); continue;}
             System.out.println(combinedInvURL +" returned "+ result);
           }

   }

   /*Test Valid and Invalid Ports*/
   public void testYourThirdPartition(){

    UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

    Random rand = new Random();

       for(int i = 0; i < numberOfRuns; i++ ){

           String currentScheme = selectRandom(rand,validSchemes);
           String currentPort = selectRandom(rand,validPort);
           String combinedURL = currentScheme + currentPort;

           System.out.println("\nTesting Valid Port: " + combinedURL);
           boolean result = false;

           try{result= urlVal.isValid(combinedURL);}
            catch(Error e)
            {System.out.println(combinedURL +" caused " +e); continue;}
             System.out.println(combinedURL +" returned "+ result);
        }

       for(int i = 0; i < numberOfRuns; i++ ){

           String currentInvScheme = selectRandom(rand,validSchemes);
           String currentInvPort = selectRandom(rand,invalidPort);
           String combinedInvURL = currentInvScheme + currentInvPort;

           System.out.println("\nTesting invalid Port: " + combinedInvURL);

           boolean result = false;

           try{result= urlVal.isValid(combinedInvURL);}
            catch(Error e)
            {System.out.println(combinedInvURL +" caused " +e); continue;}
             System.out.println(combinedInvURL +" returned "+ result);
        }
   }

   /*Test Valid and Invalid Path*/
   public void testYourForthPartition(){

    UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

    Random rand = new Random();

       for(int i = 0; i < numberOfRuns; i++ ){

           String currentScheme = "http://";
           //String currentScheme = selectRandom(rand,validSchemes);
           String currentPath = selectRandom(rand,validPath);
           String currentAuthority = selectRandom(rand,validAuthority);
           String combinedURL = currentScheme + currentAuthority + currentPath;

           System.out.println("\nTesting Valid Path: " + combinedURL);
           boolean result = false;

           try{result= urlVal.isValid(combinedURL);}
            catch(Error e)
            {System.out.println(combinedURL +" caused " +e); continue;}
             System.out.println(combinedURL +" returned "+ result);
        }

       for(int i = 0; i < numberOfRuns; i++ ){

           String currentInvScheme = "http://";
           //String currentInvScheme = selectRandom(rand,validSchemes);
           String currentInvPath = selectRandom(rand,invalidPath);
           String currentInvAuthority = selectRandom(rand,invalidAuthority);
           String combinedInvURL = currentInvScheme + currentInvAuthority + currentInvPath;

           System.out.println("\nTesting invalid Path: " + combinedInvURL);

           boolean result = false;

           try{result= urlVal.isValid(combinedInvURL);}
            catch(Error e)
            {System.out.println(combinedInvURL +" caused " +e); continue;}
             System.out.println(combinedInvURL +" returned "+ result);
        }
   }
   /*Testing Random Combination with query*/
   public void testYourFifthPartition()
   {
       UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
       Random rand = new Random();

       for(int i = 0; i < numberOfRuns; i++ ){

           String currentScheme = "http://";
           String currentPath = selectRandom(rand,validPath);
           String currentAuthority = selectRandom(rand,validAuthority);
           String currentQuery = selectRandom(rand,validQuery);
           String combinedURL = currentScheme + currentAuthority + currentPath + currentQuery;

           System.out.println("\nTesting Valid Query: " + combinedURL);
           boolean result = false;

           try{result= urlVal.isValid(combinedURL);}
            catch(Error e)
            {System.out.println(combinedURL +" caused " +e); continue;}
             System.out.println(combinedURL +" returned "+ result);
        }

   }
   //You need to create more test cases for your Partitions if you need to

   public void testIsValid()
   {
     int numOfBugs = 0;     // num of bugs.
     int length = 10;       // num of times to loop.
     int k = 0;             // index of bug.

     // Declare valid pieces of the URL.
     String[] badUrls = new String[length];
     String[] trueSchemes = {"http://", "", "h3tp://"};
     String[] trueAuthority = {"www.google.com", "google.com"};
     String[] truePort = {":80", ":9", ":100"};
     String[] truePath = {"/test1", "/"};
     String[] trueOptions = {"/test1", "/test1/test1", " "};
     String[] trueQueries = {"?action=view", " "};


     // Make random for each round.
     // Then, loop through.
     System.out.println("\nChecking valid URL pieces:\n");
     for(int i = 0; i < length; i++)
     {
       // Get a random item from the array to simulate randomly putting them together.
       int schemeInt = (int) (Math.random() * 2);
       int authorityInt = (int) (Math.random() * 2);
       int portInt = (int) (Math.random() * 3);
       int pathInt = (int) (Math.random() * 2);
       int optionsInt = (int) (Math.random() * 3);
       int queriesInt = (int) (Math.random() *2);

       // Construct it all into a string.
       String url = trueSchemes[schemeInt] + trueAuthority[authorityInt] + truePort[portInt] + truePath[pathInt] + trueQueries[queriesInt];
       UrlValidator validator = new UrlValidator();

       // Then, check if it is valid by passing it into the isValid function.
       boolean valid = validator.isValid(url);

       // If rejected, store it in bug container.
       if(valid == false) {
         numOfBugs++;
         badUrls[k] = url;
         k++;
       }

     } // End for loop.


     // Print out results to console.
     System.out.println("\nNumber of Bugs: " + numOfBugs + "\n");
     System.out.println("\nRejected URLs: \n");
     // Print them out line by line.
     for (int j = 0; j < badUrls.length; j++)
     {
       if(badUrls[j] != null){
       System.out.println(badUrls[j] + "\n");
       }

     } // End for loop.

   }

}

 