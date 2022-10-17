// https://pmichaels.net/2022/08/06/wiremock-net/
using WireMock.RequestBuilders;
using WireMock.ResponseBuilders;
using WireMock.Server;

var request = Request.Create()
    .WithPath("/test")
    .UsingGet();

var response = Response.Create()
    .WithStatusCode(200)
    .WithBody("Hello WireMock!");

WireMockServer wireMockServer = WireMockServer.Start(1234);
wireMockServer
    .Given(request)
    .RespondWith(response);


HttpClient client = new HttpClient();
var result = await client.GetAsync("http://localhost:1234/test");
if (result != null && result.IsSuccessStatusCode)
{
   var output = await result.Content.ReadAsStringAsync();
   Console.WriteLine(output);
}
