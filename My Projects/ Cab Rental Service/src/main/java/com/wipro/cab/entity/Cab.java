package com.wipro.cab.entity;

public class Cab {
    private int cabId;
    private String cabType;
    private String regNo;
    private boolean isAvailable;

    public Cab(int cabId, String cabType, String regNo, boolean isAvailable) {
        this.cabId = cabId;
        this.cabType = cabType;
        this.regNo = regNo;
        this.isAvailable = isAvailable;
    }

    public int getCabId() {
        return cabId;
    }

    public void setCabId(int cabId) {
        this.cabId = cabId;
    }

    public String getCabType() {
        return cabType;
    }

    public void setCabType(String cabType) {
        this.cabType = cabType;
    }

    public String getRegNo() {
        return regNo;
    }

    public void setRegNo(String regNo) {
        this.regNo = regNo;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void setAvailable(boolean available) {
        isAvailable = available;
    }
}
