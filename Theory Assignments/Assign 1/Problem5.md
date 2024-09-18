Name = Soofiyan Imran
Roll NUmber = k24-0684
Section = C
Date = September 19 2024
Description = Asking the user crop type , rain in last 24 hours and asking user given crop type soil moisture . Checking the relevant conditions in each type and returning the relevant output

Psedocode
START
INPUT Crop_type,Rain_in_last_24_hours
  IF Crop_type = "Wheat"
    INPUT "Soil_moisture"
    IF Soil_moisture < 30 and  Rain_in_last_24_hours = 'NO'
      return 1
    ELSE 
      return 0
  ELSE IF Crop_type = "Corn"
     INPUT "Soil_moisture"
     IF Soil_moisture < 40 
       return 1
     ELSE 
      return 0
  ELSE IF Crop_type = "Wheat"
    INPUT "Soil_moisture"
    IF Soil_moisture < 25 and  Rain_in_last_24_hours = 'YES'
      return 1
    ELSE 
      return 0
END
      
![WhatsApp Image 2024-09-18 at 4 37 44 PM (3)](https://github.com/user-attachments/assets/b8f08c9d-97bd-426b-9b00-3d9a5cf25534)
