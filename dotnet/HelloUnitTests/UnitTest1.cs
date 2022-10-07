namespace HelloUnitTests;

public class UnitTest1
{
    [Fact]
    public void TestPassing()
    {
        Assert.Equal(4, Add(2, 2));
    }

    [Fact]
    public void TestFailing()
    {
        Assert.Equal(5, Add(2, 2));
    }

    int Add(int x, int y)
    {
        return x + y;
    }
}