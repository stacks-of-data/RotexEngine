use crate::error::Error;
use rotex_types::{
    CreatedResources, Extent2D, ResourceBatchCreate, ResourceBatchUpdate, RhiCommand,
    SurfaceDescriptor, TextureId, TextureReadback,
};

pub trait GpuBackend {
    fn attach_surface(&mut self, surface_descriptor: SurfaceDescriptor) -> Result<(), Error>;

    fn create_resources(
        &mut self,
        descriptor: ResourceBatchCreate,
    ) -> Result<CreatedResources, Error>;

    fn update_resources(&mut self, descriptor: ResourceBatchUpdate) -> Result<(), Error>;

    fn execute(&mut self, commands: &[RhiCommand]) -> Result<(), Error>;

    fn resize(&mut self, extent: Extent2D) -> Result<(), Error>;

    fn read_texture(&mut self, id: TextureId) -> Result<TextureReadback, Error>;

    fn invalidate_command_cache(&mut self) {}

    fn destroy(self: Box<Self>);
}
