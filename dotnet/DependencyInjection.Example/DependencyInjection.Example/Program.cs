// https://learn.microsoft.com/en-us/dotnet/core/extensions/dependency-injection
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using DependencyInjection.Example;


var builder = Host.CreateDefaultBuilder(args);

builder.ConfigureServices(
    services =>
        services.AddHostedService<Worker>()
            .AddScoped<IMessageWriter, MessageWriter>());

var host = builder.Build();
host.Run();

static IHostBuilder CreateHostBuilder(string[] args) =>
    Host.CreateDefaultBuilder(args)
        .ConfigureServices((_, services) =>
            services.AddHostedService<LoggerWorker>()
                    .AddScoped<IMessageWriter, LoggingMessageWriter>());

var builder2 = CreateHostBuilder(args);
var host2 = builder2.Build();
host2.Run();
