package com.wipro.hotel.entity;

public class Offer {

    public double getOffer(String roomType, double billAmount) {
        if (roomType.equals("AC")) {
            if (billAmount > 5000 && billAmount <= 10000) {
                return 12.0;
            } else if (billAmount > 10000) {
                return 18.0;
            }
        } else if (roomType.equals("Non-AC")) {
            if (billAmount > 10000) {
                return 3.0;
            }
        }
        return 0.0;
    }
}
