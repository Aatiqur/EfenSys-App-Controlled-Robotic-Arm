package com.example.armappp;

public class DataSend
{


    private String data;

    public DataSend() //null constructor
    {
    }

    public DataSend(String data) //sending constructor
    {
        this.data = data;
    }

    public String getData() //getterMethod
    {
        return data;
    }

    public void setData(String data) //setterMethod
    {
        this.data = data;
    }
}
