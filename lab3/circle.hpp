class Circle{
    private:
        double r;
        double center[2];
    public:
        Circle(double r, double x, double y)
        {
            setRadius(r);
            setCenter(x, y);
        }
        Circle(double r)
        {
            setRadius(r);
            setCenter(0, 0);
        }
        void setRadius(double r)
        {
            this->r = r;   
        }
        void setCenter(double x, double y)
        {
            this->center[0] = x;
            this->center[1] = y;   
        }
        double getArea()
        {
            return 3.14*r*r;
        }
        double getCircumference()
        {
            return 2*3.14*r;
        }
        ~Circle()
        {
            return;
        }
};