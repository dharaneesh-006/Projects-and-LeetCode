package com.wipro.hotel.main;

import com.wipro.hotel.service.HotelBillService;

import java.text.SimpleDateFormat;
import java.util.Date;

public class MainClass {

    public static void main(String[] args) throws Exception {
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        HotelBillService h = new HotelBillService();

        Date bookingDate = formatter.parse("11/07/2017");
        Date departureDate = formatter.parse("12/07/2017");

        System.out.println(h.calculateBill("CC598466", bookingDate, departureDate, "Non-AC"));
    }
}
