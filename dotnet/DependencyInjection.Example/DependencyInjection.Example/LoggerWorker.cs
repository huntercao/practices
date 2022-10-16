using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;

public class LoggerWorker : BackgroundService
{
   private readonly ILogger<LoggerWorker> _logger;

   public LoggerWorker(ILogger<LoggerWorker> logger) =>
       _logger = logger;

   protected override async Task ExecuteAsync(CancellationToken stoppingToken)
   {
      while (!stoppingToken.IsCancellationRequested)
      {
         _logger.LogInformation("Worker running at: {time}", DateTimeOffset.Now);
         await Task.Delay(1000, stoppingToken);
      }
   }
}
