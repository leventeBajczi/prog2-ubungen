class Rectangle
{
    private:
        double height, width;
    public:
        Rectangle(double h, double w)
        {
            setHeight(h);
            setWidth(w);
        }      
        Rectangle(double h)
        {
            setHeight(h);
        }
        double getArea()
        {
            return height*width;
        }
        double getHeight()
        {
            return height;
        }
        double getWidth()
        {
            return width;
        }
        void setHeight(double h)
        {
            //setting height
        }
        void setWidth(double w)
        {
            //setting width
        }
        double getPerimeter();
};