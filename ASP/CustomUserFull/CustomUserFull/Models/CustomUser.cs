using Microsoft.AspNetCore.Identity;

namespace CuctomUserFull.Models
{
    public class CustomUser : IdentityUser
    {
        public string Status { get; set; }
    }
}
