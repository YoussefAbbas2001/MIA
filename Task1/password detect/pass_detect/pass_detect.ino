/*
Date : 25/8/2021
Author: youssef abbas

password Checks and Cipher
Note : i am Handling number and uppercase letter
*/
#define led 13

String pass;             //String we will input
String real = "abbas2009";   //real password we want to login

//function prototype
int check_pass(int);
void caesar_cipher();
void blink(int,int);

void setup() 
{
    pinMode(led,OUTPUT);
    Serial.begin(9600);  
    delay(1000);   
    //welcome text
    Serial.print("Welcome sir, Enter password \n");
    Serial.print("----------------------------\n");     
}
 
void loop()
{
  if(Serial.available())   //go to it when Entered something in input prompt
  {
    Serial.print("You Enter Password : ");
    pass = Serial.readString();          //read password from user
    Serial.print(pass);                  //display it in the screen
    
    if(check_pass(pass))                 //check password to password in Database
    {
              
      Serial.print(">>>Right password\n"); //display approval text
      digitalWrite(led,HIGH);
      delay(2000);                         //delay 2 sec in high mode
      digitalWrite(led,LOW);
      Serial.print("____________________________");
      Serial.print("\n\n");
      caesar_cipher();           //apply Caesar Cipher on the text
    }
    else
    {
      Serial.print(">>>Wrong password\n");   //display refusal text
      blink(100,10);                       //100 ms delay and 10 iterate
      Serial.print("____________________________");
      Serial.print("\n\n");
    }
  }
}

//function Implementation
void caesar_cipher()
{
  /*
  function apply caesar_cipher in which each character shifted by 1
  */
  
  for(byte i = 0;i < real.length();i++)
  {
    //Handling Alphabit
    if(isAlpha(real[i]))
    {
      if(real[i] != 'z' && real[i] != 'Z')   //Except that character is z/Z to wrap around
      {
        real[i]++;  //increamnt ASCII
      }
      else
      {
        real[i] = (real[i]=='z')? 'a':'A'; //to wrap around alphabit
      }
    }
    //Handling Digits
    else if(isDigit(real[i]))
    {
      if(real[i] != '9')   //Except that character is z/Z to wrap around
      {
        real[i]++;  //increamnt ASCII
      }
      else
      {
        real[i] = '0'; //to wrap around Digit
      }
    }    
  }
}
int check_pass(String password)
{
  /*
  About : Check if this password similar with the original one in Database
  
  */
  if(password.length()-1 == real.length()) //Check Equal Length
  {
    /*
    Note: reason we compare with length-1 beacause it consider
    the enter is one character when press string in
    Serial Monitor
    */
    for(byte i =0;i<real.length();i++)
    {
      if (password[i] == real[i])
      {
       return 1;  //check every charater if one wrong return 0
      }
    }
  }
  //if all character are Identical return 1
  return 0;
}

void blink(int del,int iter=10)
{
  for(int i=0;i<iter;i++)
  {
    digitalWrite(led,HIGH);
    delay(del);
    digitalWrite(led,LOW);
    delay(del);
  }
}
