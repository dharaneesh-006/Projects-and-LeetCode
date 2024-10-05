package com.wipro.hotel.service;

import com.wipro.hotel.entity.Customer;
import com.wipro.hotel.entity.Offer;
import com.wipro.hotel.exception.InvalidDataException;
import com.wipro.hotel.exception.InvalidRoomTypeException;

import java.util.Date;

public class HotelBillService {

    public String validateData(String customerId, Date bookingDate, Date departureDate, String roomType) {
        if (customerId == null || customerId.length() != 8) {
            try {
                throw new InvalidDataException();
            } catch (InvalidDataException e) {
                return e.toString();
            }
        }

        if (bookingDate.compareTo(departureDate) >= 0) {
            try {
                throw new InvalidDataException();
            } catch (InvalidDataException e) {
                return e.toString();
            }
        }

        if (!roomType.equals("AC") && !roomType.equals("Non-AC")) {
            try {
                throw new InvalidRoomTypeException();
            } catch (InvalidRoomTypeException e) {
                return e.toString();
            }
        }

        return "Valid";
    }

    public int getDaysStayed(Date bookingDate, Date departureDate) {
        long difference = departureDate.getTime() - bookingDate.getTime();
        return (int) (difference / (1000 * 60 * 60 * 24));
    }

    public String calculateBill(String customerId, Date bookingDate, Date departureDate, String roomType) {
        String validation = validateData(customerId, bookingDate, departureDate, roomType);
        if (!validation.equals("Valid")) {
            return validation;
        }

        Customer customer = new Customer(customerId, bookingDate, departureDate, roomType);
        int daysStayed = getDaysStayed(bookingDate, departureDate);
        double tariffPerDay = customer.getTariffPerDay();
        double billAmount = daysStayed * tariffPerDay;

        double tax;
        if (billAmount <= 5000) {
            tax = billAmount * 0.05;
        } else if (billAmount <= 10000) {
            tax = billAmount * 0.10;
        } else {
            tax = billAmount * 0.20;
        }

        double totalBillAmount = billAmount + tax;

        Offer offer = new Offer();
        double offerPercentage = offer.getOffer(roomType, totalBillAmount);
        double discount = totalBillAmount * offerPercentage / 100;

        customer.setBillAmount(totalBillAmount - discount);

        return customer.toString();
    }
}
