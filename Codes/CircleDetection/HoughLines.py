import sys
import cv2 as cv
import numpy as np

def main(argv):
    cap = cv.VideoCapture(0)
    while(True):
        """
        for i in range(30):
            ret,background = cap.read()
         
        # Laterally invert the image / flip the image.
        background = np.flip(background,axis=1)
        """
        # Capture frame-by-frame
        ret, src = cap.read()
        """
            # Laterally invert the image / flip the image
        src  = np.flip(src, axis=1)
         
        # converting from BGR to HSV color space
        hsv = cv.cvtColor(src,cv.COLOR_BGR2HSV)
         
        # Range for lower red
        lower_red = np.array([0,120,70])
        upper_red = np.array([10,255,255])
        mask1 = cv.inRange(hsv, lower_red, upper_red)
         
        # Range for upper range
        lower_red = np.array([170,120,70])
        upper_red = np.array([180,255,255])
        mask2 = cv.inRange(hsv,lower_red,upper_red)
         
        # Generating the final mask to detect red color
        mask1 = mask1+mask2
        mask1 = cv.morphologyEx(mask1, cv.MORPH_OPEN, np.ones((3,3),np.uint8))
        mask1 = cv.morphologyEx(mask1, cv.MORPH_DILATE, np.ones((3,3),np.uint8))
         
         
        #creating an inverted mask to segment out the cloth from the frame
        #mask2 = cv.bitwise_not(mask1)
         
         
        #Segmenting the cloth out of the frame using bitwise and with the inverted mask
        src = cv.bitwise_and(src,src,mask=mask1)
"""
        src = src[100:300,100:500]
        src = cv.resize(src, (800,400))
        gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
        
        
        gray = cv.medianBlur(gray, 5)
        
        
        rows = gray.shape[0]
        circles = cv.HoughCircles(gray, cv.HOUGH_GRADIENT, 1, rows / 2,
                                   param1=100, param2=40,
                                   minRadius=0 ,maxRadius=40)
        
        
        if circles is not None:
            circles = np.uint16(np.around(circles))
            for i in circles[0, :]:
                center = (i[0], i[1])
                if center[0] + center[1] is not 0:
                    print(center)
                # circle center
                cv.circle(gray, center, 1, (0, 100, 100), 3)
                # circle outline
                radius = i[2]
                cv.circle(gray, center, radius, (255, 0, 255), 3)
        
        
        cv.imshow("detected circles", gray)
        
        if cv.waitKey(1) & 0xFF == ord('q'):
            break
    cap.release()
    cv.destroyAllWindows()
    
    return 0
if __name__ == "__main__":
    main(sys.argv[1:])